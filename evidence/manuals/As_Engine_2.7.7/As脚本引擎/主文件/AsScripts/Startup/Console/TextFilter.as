
bool ImCharIsBlankA(uint8 c) 
{
	return c == ' ' || c == '\t'; 
}

// [Internal]
class ImGuiTextFilter_TextRange
{
	string@ text;
	int b;
	int e;

	ImGuiTextFilter_TextRange() { b = e = 0; }
	ImGuiTextFilter_TextRange(const string& _text, int _b, int _e) { text = _text; b = _b; e = _e; }
	int begin() const { return b; }
	int end() const { return e; }
	bool            empty() const { return b == e; }
	void  split(uint8 separator, array<ImGuiTextFilter_TextRange>& outArr) 
	{
		outArr.Resize(0);
		int wb = b;
		int we = wb;
		while (we < e)
		{
			if (text[we] == separator)
			{
				outArr.Push(ImGuiTextFilter_TextRange(text, wb, we));
				wb = we + 1;
			}
			we++;
		}
		if (wb != we)
			outArr.Push(ImGuiTextFilter_TextRange(text, wb, we));
	}
};

// Helper: Parse and apply text filters. In format "aaaaa[,bbbb][,ccccc]"
class ImGuiTextFilter
{

    ImGuiTextFilter(const string& default_filter = "") {
        InputBuf = default_filter;
        Build();
    }
    bool      Draw(const string& label = "Filter (inc,-exc)", float width = 0.0f)    // Helper calling InputText+Build
	{
		if (width != 0.0f)
			ImGui_PushItemWidth(width);
		bool value_changed = ImGui_InputText(label, InputBuf);
		if (width != 0.0f)
			ImGui_PopItemWidth();
		if (value_changed)
			Build();
		return value_changed;
		
	}
    bool      PassFilter(const string& text) const
	{
		if (Filters.IsEmpty())
			return true;

		for (int i = 0; i != Filters.GetSize(); i++)
		{
			const ImGuiTextFilter_TextRange@ f = Filters[i];
			if (f.empty())
				continue;
			if (f.text[f.b] == '-')
			{
				// Subtract
				if (text.Find(f.text.Substring(1), 0, false) != NPOS)
					return false;
			}
			else
			{
				// Grep
				if (text.Find(f.text, 0, false) != NPOS)
					return true;
			}
		}
		return false;
		
	}
    void      Build()
	{
		Filters.Resize(0);
		ImGuiTextFilter_TextRange input_range(InputBuf, 0, InputBuf.Length());
		input_range.split(',', Filters);

		CountGrep = 0;
		for (int i = 0; i != Filters.GetSize(); i++)
		{
			ImGuiTextFilter_TextRange@ f = Filters[i];
			while (f.b < f.e && ImCharIsBlankA(f.text[f.b]))
				f.b++;
			while (f.e > f.b && ImCharIsBlankA(f.text[f.e-1]))
				f.e--;
			if (f.empty())
				continue;
			if (Filters[i].text[Filters[i].b] != '-')
				CountGrep += 1;
		}
		
	}
    void                Clear() { InputBuf.Clear(); Build(); }
    bool                IsActive() const { return !Filters.IsEmpty(); }

    string                InputBuf;
    array<ImGuiTextFilter_TextRange> Filters; 
    int                 CountGrep;
	
};