#include "../PScriptLib/AsHelper.as"

enum UVTransform 
{
    None,
    FlipX,
    FlipXY,
    FlipY,
};


// 图片精灵，用来在屏幕上显示图片
class AsSprite{
    /*
    屏幕内的相对大小，这是个相对值 最小值为(0, 0) 最大值 为 (1, 1)
    如果想设置成屏幕大小，就填 (1, 1)
    */
    Vector2 Size = Vector2(1, 1);
    /*
    屏幕内的相对位置，这是个相对值 最小值为(0, 0) 最大值 为 (1, 1)
    如果要放置在屏幕左上角，就填 (0, 0)
    如果要放置在屏幕右下角，就填 (1, 1)
    */
    Vector2 Position;
    // 背景色, rgba , 0.0~1.0
    Vector4 BgColor;
    /* 
    锚点，最小值为(0, 0) 最大值 为 (1, 1)
    其中 (0, 0) 指的是左上角，
    其中 (1, 1) 指的是右下角，
    */
    Vector2 Anchor;
    /*
    色调，分别是(红,绿,蓝,透明度)
    如 (1,1,1,0.5) 表示图片透明度为一半
    */
    Vector4 Tint = Vector4(1,1,1,1);
    Vector2 UV0 = Vector2(0, 0); // UV 坐标左上角
    Vector2 UV1 = Vector2(1, 1); // UV 坐标右下角

    // UV 变换类型
    UVTransform UVTransform = None;

    // 图片资源
    private Image@ _previousImage; // 用来持有上一张图片的句柄，避免某些因素导致游戏崩溃
    private Image@ _image;
    private string _filename;

    private int _id;

    // 载入图片，参数为Image
    void Load(Image@ inputImage){
        @_previousImage = _image;
        @_image = inputImage;
        _filename = "";
    }

    // 载入图片，参数为文件名
    void Load(string filename){
        if (_filename == filename){
            return;
        }
        Image @itempImage = AsLoadImageFile(filename);
        if (@itempImage == null){
            Print("读取图片失败 " + filename);
            PrintSystemText("读取图片失败 " + filename);
            return;
        }
        @_previousImage = _image;
        @_image = itempImage;
        _filename = filename;
    }

    // 画图，调用一次就画一帧
    void Draw(){
        if (@_image == null){
            return;
        }
        
        // 设置窗口大小和位置
        auto screenSize = ImGui_GetDisplaySize();
        ImGui_SetNextWindowSize(screenSize * Size);
        ImGui_SetNextWindowPos(screenSize * (Position - Size * Anchor));

        // 窗口基本属性
        int windowFlags = 
            ImGuiWindowFlags_NoTitleBar | // 无标题栏
            ImGuiWindowFlags_NoMove |  // 禁止拖动
            ImGuiWindowFlags_NoResize |  // 禁止手动调整窗口大小
            ImGuiWindowFlags_AlwaysAutoResize |  // 总是自动调整窗口大小
            ImGuiWindowFlags_NoInputs | // 穿透鼠标
            ImGuiWindowFlags_NoScrollbar | // 无滚动条
            0;
        ImGui_PushStyleColor(ImGuiCol_WindowBg, BgColor);

        // 窗口边框宽度为0
        ImGui_PushStyleVar(ImGuiStyleVar_WindowPadding,  Vector2(0,0));
        ImGui_PushStyleVar(ImGuiStyleVar_IndentSpacing,  0);
        ImGui_PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        
        // 画窗口
        bool open = true;
        if (_id == 0){
            _id = Rand(10000000);
        }
        if (ImGui_Begin("图片精灵" + _id, open, windowFlags)){
            Vector2 transformedUv0;
            Vector2 transformedUv1;
            GetTransformedUV(UVTransform, UV0, UV1, transformedUv0, transformedUv1);
            ImGui_Image(_image, screenSize * Size, transformedUv0, transformedUv1, Tint);
        }

        ImGui_PopStyleVar();
        ImGui_PopStyleVar();
        ImGui_PopStyleVar();
        ImGui_PopStyleColor();

        ImGui_End();
    }

    private void Swap(Vector2& a, Vector2& b)
    {
        Vector2 c = a;
        a = b;
        b = a;
    }

    private void GetTransformedUV(UVTransform transform, Vector2 uv0, Vector2 uv1, Vector2& transformedUv0, Vector2& transformedUv1)
    {
        // 获取原始四个角的 UV 坐标
        float u0 = uv0.x;
        float v0 = uv0.y;
        float u1 = uv1.x;
        float v1 = uv1.y;

        // 统一坐标区间，处理非规范方向的 UV（如 UV0 > UV1）
        float umin = Min(u0, u1);
        float umax = Max(u0, u1);
        float vmin = Min(v0, v1);
        float vmax = Max(v0, v1);

        // 定义四个原始角
        Vector2[] uv = {
            Vector2( u0, v0 ), // top-left
            Vector2( u1, v0 ), // top-right
            Vector2( u1, v1 ), // bottom-right
            Vector2( u0, v1 )  // bottom-left
        };

        // 映射顺序表：每种旋转对应新的 UV 顺序（旋转是逆时针）
        int[] indices(4);

        switch (transform) {
            case None:
                indices[0] = 0; indices[1] = 1; indices[2] = 2; indices[3] = 3;
                break;
            case FlipX:
                indices[0] = 1; indices[1] = 2; indices[2] = 3; indices[3] = 0;
                break;
            case FlipXY:
                indices[0] = 2; indices[1] = 3; indices[2] = 0; indices[3] = 1;
                break;
            case FlipY:
                indices[0] = 3; indices[1] = 0; indices[2] = 1; indices[3] = 2;
                break;
        }

        // 根据旋转设置新顺序
        Vector2[] uv_transformed = {
            uv[indices[0]], // top-left
            uv[indices[1]], // top-right
            uv[indices[2]], // bottom-right
            uv[indices[3]]  // bottom-left
        };

        // 最终设置 UV0（左上） 和 UV1（右下）
        transformedUv0 = uv_transformed[0];
        transformedUv1 = uv_transformed[2];
    }
}