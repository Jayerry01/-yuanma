
#include "Console/TextFilter.as"

// Demonstrating creating a simple console window, with scrolling, filtering, completion and history.
// For the console example, here we are using a more C++ like approach of declaring a class to hold the data and the functions.
ImGuiTextFilter filter;

bool g_reclaim_focus = false;

// Portable helpers
string Strdup(const string& str)                             { return str; }
void  Strtrim(string& str)                                  { str = str.Trimmed(); }

class ExampleAppConsole
{
    string                  InputBuf;
    array<string>       Items;
    bool                  ScrollToBottom;
    array<string>       History;
    int                   HistoryPos;    // -1: new line, 0..History.Size-1 browsing history.
    array<string> Commands;

    ExampleAppConsole()
    {
        ClearLog();
        InputBuf.Clear();
        HistoryPos = -1;
        Commands.Push("HELP");
        Commands.Push("HISTORY");
        Commands.Push("CLEAR");
        Commands.Push("CLASSIFY");  // "classify" is only here to provide an example of "C"+[tab] completing to "CL" and displaying matches.

        AddLog("欢迎使用As脚本引擎");
    }
    ~ExampleAppConsole()
    {
        ClearLog();
        History.Clear();
    }

    

    void    ClearLog()
    {
        Items.Clear();
        ScrollToBottom = true;
    }

    void DeleteFrontLog(){
        while(Items.length > 100){
            Items.Erase(0);
        }
    }

    void    AddLog(const string& text)
    {
        Items.Push(text);
        ScrollToBottom = true;
        DeleteFrontLog();
    }
	
	void    AddLog(const array<string>& arr)
    {
        Items.Push(Join(arr, " "));
        ScrollToBottom = true;
        DeleteFrontLog();
    }

    void    Draw(const string& title, bool& p_open)
    {
        auto screenSize = ImGui_GetDisplaySize();
        ImGui_SetNextWindowSize(Vector2(screenSize.x,screenSize.y * 0.4));
        ImGui_SetNextWindowPos(Vector2(0,0));
        if (!ImGui_Begin(title, p_open, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize))
        {
            ImGui_End();
            return;
        }

        // As a specific feature guaranteed by the library, after calling Begin() the last Item represent the title bar. So e.g. IsItemHovered() will return true when hovering the title bar.
        // Here we create a context menu only available from the title bar.
        if (ImGui_BeginPopupContextItem())
        {
            if (ImGui_MenuItem("关闭控制台")){
                p_open = false;
			}
            ImGui_EndPopup();
        }

        //ImGui_TextWrapped("This example implements a console with basic coloring, completion and history. A more elaborate implementation may want to store entries along with extra data such as timestamp, emitter, etc.");
        //ImGui_TextWrapped("Enter 'HELP' for help, press TAB to use text completion.");

        // TODO: display items starting from the bottom

        //if (ImGui_SmallButton("Add Dummy Text")) { AddLog(Items.GetSize() + " some text"); AddLog("some more text"); AddLog("display very important message here!"); } ImGui_SameLine();
        //if (ImGui_SmallButton("Add Dummy Error")) { AddLog("[error] something went wrong"); } ImGui_SameLine();
        if (ImGui_SmallButton("清屏")) { ClearLog(); } ImGui_SameLine();
        bool copy_to_clipboard = ImGui_SmallButton("复制"); ImGui_SameLine();
        if (ImGui_SmallButton("滚动到底部")) ScrollToBottom = true;
        //static float t = 0.0f; if (ImGui_GetTime() - t > 0.02f) { t = ImGui_GetTime(); AddLog("Spam %f", t); }

        ImGui_Separator();
        /*
        ImGui_PushStyleVar(ImGuiStyleVar_FramePadding, Vector2(0,0));
        
        filter.Draw("Filter (\"incl,-excl\") (\"error\")", 180);
        ImGui_PopStyleVar();
        ImGui_Separator();
        */
        const float footer_height_to_reserve = ImGui_GetStyle().ItemSpacing.y + ImGui_GetFrameHeightWithSpacing(); // 1 separator, 1 input text
        ImGui_BeginChild("ScrollingRegion", Vector2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar); // Leave room for 1 separator + 1 InputText
        if (ImGui_BeginPopupContextWindow())
        {
            if (ImGui_Selectable("清屏")) ClearLog();
            ImGui_EndPopup();
        }

        // Display every line as a separate entry so we can change their color or add custom widgets. If you only want raw text you can use ImGui_TextUnformatted(log.begin(), log.end());
        // NB- if you have thousands of entries this approach may be too inefficient and may require user-side clipping to only process visible items.
        // You can seek and display only the lines that are visible using the ImGuiListClipper helper, if your elements are evenly spaced and you have cheap random access to the elements.
        // To use the clipper we could replace the 'for (int i = 0; i < Items.Size; i++)' loop with:
        //     ImGuiListClipper clipper(Items.Size);
        //     while (clipper.Step())
        //         for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++)
        // However, note that you can not use this code as is if a filter is active because it breaks the 'cheap random-access' property. We would need random-access on the post-filtered list.
        // A typical application wanting coarse clipping and filtering may want to pre-compute an array of indices that passed the filtering test, recomputing this array when user changes the filter,
        // and appending newly elements as they are inserted. This is left as a task to the user until we can manage to improve this example code!
        // If your items are of variable size you may want to implement code similar to what ImGuiListClipper does. Or split your data into fixed height items to allow random-seeking into your list.
        ImGui_PushStyleVar(ImGuiStyleVar_ItemSpacing, Vector2(4,1)); // Tighten spacing
        if (copy_to_clipboard)
            ImGui_LogToClipboard();
        Vector4 col_default_text = ImGui_GetStyleColorVec4(ImGuiCol_Text);
        for (int i = 0; i < Items.GetSize(); i++)
        {
            string@ item = Items[i];
            if (!filter.PassFilter(item))
                continue;
            Vector4 col = col_default_text;
            //if (item.Find("[error]") != NPOS) col = Vector4(1.0f,0.4f,0.4f,1.0f);
            if (item.Find("Error") != NPOS) col = Vector4(1.0f,0.4f,0.4f,1.0f);
            if (item.Find("Warn") != NPOS) col = Vector4(0.75f,0.75f,0.0f,1.0f);
            else if (item.Substring(0, 2).Compare("# ", false) == 0) col = Vector4(1.0f,0.78f,0.58f,1.0f);
            ImGui_PushStyleColor(ImGuiCol_Text, col);
            ImGui_Text(item);
            ImGui_PopStyleColor();
        }
        if (copy_to_clipboard)
            ImGui_LogFinish();
        if (ScrollToBottom)
            ImGui_SetScrollHereY(1.0f);
        ScrollToBottom = false;
        ImGui_PopStyleVar();
        ImGui_EndChild();
        ImGui_Separator();

        // Command-line
		ImGuiInputTextCallback @textEditCallback = ImGuiInputTextCallback(this.TextEditCallback);
        if (ImGui_InputText("输入", InputBuf, ImGuiInputTextFlags_EnterReturnsTrue|ImGuiInputTextFlags_CallbackCompletion|ImGuiInputTextFlags_CallbackHistory, textEditCallback))
        {
            Strtrim(InputBuf);
            if (InputBuf.Length() > 0)
                ExecCommand(InputBuf);
            InputBuf.Clear();
            g_reclaim_focus = true;
        }

        // Auto-focus on window apparition
        ImGui_SetItemDefaultFocus();
        if (g_reclaim_focus)
            ImGui_SetKeyboardFocusHere(-1); // Auto focus previous widget

        g_reclaim_focus = false;

        ImGui_End();
    }

    void    ExecCommand(const string& command_line)
    {
        AddLog("# " + command_line);

        // Insert into history. First find match and delete it so it can be pushed to the back. This isn't trying to be smart or optimal.
        HistoryPos = -1;
        for (int i = History.GetSize()-1; i >= 0; i--)
            if (Stricmp(History[i], command_line) == 0)
            {
                History.Erase(i);
                break;
            }
        History.Push(Strdup(command_line));

        // Process command
        if (Stricmp(command_line, "CLEAR") == 0)
        {
            ClearLog();
        }
        else if (Stricmp(command_line, "HELP") == 0)
        {
            AddLog("Commands:");
            for (int i = 0; i < Commands.GetSize(); i++)
                AddLog("- " + Commands[i]);
        }
        else if (Stricmp(command_line, "HISTORY") == 0)
        {
            int first = History.GetSize() - 10;
            for (int i = first > 0 ? first : 0; i < History.GetSize(); i++)
                AddLog(string(i) + ": " + History[i]);
        }
        else
        {
            ExecuteLine(command_line);
        }
    }

    int     TextEditCallback(ImGuiInputTextCallbackData& data)
    {
        //AddLog("cursor: %d, selection: %d-%d", data->CursorPos, data->SelectionStart, data->SelectionEnd);
        switch (data.EventFlag)
        {
        case ImGuiInputTextFlags_CallbackCompletion:
            {
                // Example of TEXT COMPLETION

                // Locate beginning of current word
                int word_end = data.CursorPos;
                int word_start = word_end;   
                while (word_start > 0)
                {
                    const uint8 c = data.Buf[word_start-1];
                    if (c == ' ' || c == '\t' || c == ',' || c == ';')
                        break;
                    word_start--;
                }

                // Build a list of candidates
                array<string> candidates;
                for (int i = 0; i < Commands.GetSize(); i++)
                    if (Strnicmp(Commands[i], data.Buf.Substring(word_start), (word_end-word_start)) == 0)
                        candidates.Push(Commands[i]);

                if (candidates.GetSize() == 0)
                {
                    // No match
                    AddLog("No match for \"" + data.Buf.Substring(word_start, (word_end-word_start)) + "\"!");
                }
                else if (candidates.GetSize() == 1)
                {
                    // Single match. Delete the beginning of the word and replace it entirely so we've got nice casing
                    data.DeleteChars(word_start, (word_end-word_start));
                    data.InsertChars(data.CursorPos, candidates[0]);
                    data.InsertChars(data.CursorPos, " ");
                }
                else
                {
                    // Multiple matches. Complete as much as we can, so inputing "C" will complete to "CL" and display "CLEAR" and "CLASSIFY"
                    int match_len = word_end - word_start;
                    for (;;)
                    {
                        int c = 0;
                        bool all_candidates_matches = true;
                        for (int i = 0; i < candidates.GetSize() && all_candidates_matches; i++)
                            if (i == 0)
                                c = ToUpper(candidates[i][match_len]);
                            else if (c == 0 || c != ToUpper(candidates[i][match_len]))
                                all_candidates_matches = false;
                        if (!all_candidates_matches)
                            break;
                        match_len++;
                    }

                    if (match_len > 0)
                    {
                        data.DeleteChars(word_start, word_end-word_start);
                        data.InsertChars(data.CursorPos, candidates[0].Substring(0, match_len));
                    }

                    // List matches
                    AddLog("Possible matches:");
                    for (int i = 0; i < candidates.GetSize(); i++)
                        AddLog("- " + candidates[i]);
                }

                break;
            }
        case ImGuiInputTextFlags_CallbackHistory:
            {
                // Example of HISTORY
                const int prev_history_pos = HistoryPos;
                if (data.EventKey == ImGuiKey_UpArrow)
                {
                    if (HistoryPos == -1)
                        HistoryPos = History.GetSize() - 1;
                    else if (HistoryPos > 0)
                        HistoryPos--;
                }
                else if (data.EventKey == ImGuiKey_DownArrow)
                {
                    if (HistoryPos != -1)
                        if (++HistoryPos >= History.GetSize())
                            HistoryPos = -1;
                }

                // A better implementation would preserve the data on the current input line along with cursor position.
                if (prev_history_pos != HistoryPos)
                {
                    string history_str = (HistoryPos >= 0) ? History[HistoryPos] : "";
                    data.DeleteChars(0, data.Buf.Length());
                    data.InsertChars(0, history_str);
                }
            }
        }
        return 0;
    }
};

ExampleAppConsole@ g_console;
bool g_open = false;
 
void ScriptMessageHandler(const string&in msg){
    // 裁剪文件名
    auto pos = msg.Find(".as:", 0, false);
    if (pos == NPOS){
        pos = msg.Find(".ase:", 0, false);
    }
    string newMsg = msg;
    if (pos != NPOS){
        string filename = msg.Substring(0, pos+3);
        filename = GetFileNameAndExtension(filename);
        newMsg = filename + msg.Substring(pos+3);
    }
    g_console.AddLog(newMsg);
}
 
void OnStart()
{
    
	if (g_console is null){
		@g_console = ExampleAppConsole();
	}
    ScriptMessageCallback @callback = @ScriptMessageHandler;
    AddMessageCallback(callback);
}

void OnUpdate()
{
    if ( ImGui_IsKeyPressed(ImGuiKey_GraveAccent) )
    {
	    g_open = !g_open;
        if (g_open){
            // 定位到输入框
            g_reclaim_focus = true;
        }
    }
    if(g_open){
        // 显示鼠标
        ShowMouse();
        
        // 显示界面
		g_console.Draw("控制台", g_open);
	}
}

void OnStop(){
}