// Script API header intended to be 'force included' in IDE for AngelScript content assist / code completion

#define int8 signed char
#define int16 signed short
#define int64 long
#define uint8 unsigned char
#define uint16 unsigned short
#define uint unsigned
#define uint64 unsigned long
#define null 0
#define in
#define out
#define inout
#define is ==
#define interface struct
#define class struct
#define cast reinterpret_cast
#define mixin
#define funcdef

// 回调/委托 类型
void ScriptMessageCallback(const string&);
void ChatCallback(const string&, bool);
void ScriptMessageCallback(const string&);
void ChatCallback(const string&, bool);
int ImGuiInputTextCallback(ImGuiInputTextCallbackData&);
bool ImGuiItemGetter(int, string&);



// 游戏API
bool AddChatCallback(ChatCallback);
bool AddMessageCallback(ScriptMessageCallback);
int AddNPC(const string&, const string& = string :: EMPTY);
int Call(...);
bool CanInvokeGameAPI(const string&);
int ChangeBehavior(...);
void CharAttack(int, const string&);
void CharAttackImm(int, const string&);
void CharBaoQi(int);
void CharCreateTempItem(int, int, int, const Vector3&);
void CharDropTempItem(int, int, int);
void CharDropTempItem(int, int, int, const Vector3&, float);
void CharDropVipItem(int);
void CharDropWeapon(int);
int CharGetBaseAttrib(int, int);
array<BufferDetail> CharGetBufferList(int);
Vector3 CharGetPosition(int);
Vector3 CharGetRotation(int);
float CharGetRotationYaw(int);
void CharJump(int);
void CharJumpImm(int);
void CharLockTarget(int);
void CharRemoveBuffer(int, int);
void CharSetBaseAttrib(int, int, int);
void CharSetPosition(int, Vector3);
void CharSetRotation(int, Vector3);
void CharSetRotationYaw(int, float);
void CharShowPose(int, int);
void CharSwitchWeapon(int, bool = true);
int CloseFile(int);
void Command(const string&, const string& = string :: EMPTY, const string& = string :: EMPTY, const string& = string :: EMPTY, const string& = string :: EMPTY, const string& = string :: EMPTY, const string& = string :: EMPTY, const string& = string :: EMPTY, const string& = string :: EMPTY, const string& = string :: EMPTY, const string& = string :: EMPTY);
int CreateEffect(...);
int CreateSceneItem(const string&, const string&, const string&);
void DisableExecuteLine();
int DisableWaypoints(...);
int Distance(int, int);
int Distanve(int, int);
void EnableKeyCommand(bool);
void EnableKeyEsc(bool);
int EnableWaypoints(...);
bool EncryptScript(const string&, const string& = "", bool = false);
void EnterScene(int);
bool ExecuteFunction(const string&, const string&, ...);
bool ExecuteFunction(int, const string&, ...);
bool ExecuteLine(const string&);
void ExitScene();
int GameCallBack(const string&, int);
int GameOver(int);
int GetActivePose(int);
int GetAnger(int);
int GetAnyChar(const string&, int = 0);
int GetAttack(int);
int GetChar(const string&, int = 0);
array<int> GetCharIdList();
int GetDead(int);
int GetDefense(int);
string GetDisplayName(int);
int GetEnemy(int);
int GetGameTime();
float GetGameTimeFloat();
Vector2 GetGameWindowSize();
double GetGlobalTime();
int GetHP(int);
int GetKill(int);
int GetLeader(int);
int GetLevelScriptId();
Vector3 GetMapBoundingBoxMax();
Vector3 GetMapBoundingBoxMin();
Vector3 GetMapBoundingBoxSize();
int GetMaxHP(int);
int GetNpcScriptId(int);
Vector3 GetPosition(int);
int GetSceneItem(...);
int GetSceneItem(const string&, const string&);
int GetSceneItem(int, const string&);
int GetSceneItemCount();
int GetSceneItemId(const string&);
string GetSceneItemModelName(int);
string GetSceneItemName(int);
Vector3 GetSceneItemPosition(int);
float GetSceneItemRotationYaw(int);
int GetSceneScriptId();
int GetScriptVarInt(int, const string&);
string GetScriptVarString(int, const string&);
int GetSelf(int);
int GetSharedVarInt(const string&);
string GetSharedVarString(const string&);
int GetSpeed(int);
int GetWeapon(int);
int GetWeapon2(int);
int GetWeaponType(int);
int GetWeaponType2(int);
void InputGameKey(int, int, bool);
bool IsAlive(int);
bool IsAllowCharSwitchWeapon(int);
int IsPerforming(int);
bool IsTwoPointsVisible(const Vector3&, const Vector3&);
Image LoadImageFile(const string&);
int MakeString(string&, const string&, int);
int Misc(...);
int NetEvent(int);
int OpenFile(const string&, const string&);
int Output(...);
int Perform(...);
int Perofrm(...);
bool PlayMusic(const string&);
int PlayerPerform(...);
int Print(...);
void PrintSystemText(const string&);
int Rand(int);
int Rand(int, int);
int ReadFile(int);
void Reborn(int);
void RebornAround(int);
int RemoveNPC(int);
int Say(...);
void ServerKill(int);
void SetAggressPose(int, int);
void SetAllowCharSwitchWeapon(int, bool);
void SetDisplayName(int, const string&);
void SetKeyCommandHint(const string&, const string&, const string&);
void SetKeyEscHint(const string&, const string&, const string&);
int SetScene(...);
int SetSceneItem(...);
bool SetSceneItemPosition(int, const Vector3&);
bool SetSceneItemRotationYaw(int, float);
void SetSharedVarInt(const string&, int);
void SetSharedVarString(const string&, const string&);
int SetTarget(int, const string&, int = 0);
void SetTeam(int, int);
void ShowChatText(bool);
void ShowMouse();
int StopPerform(int);
int UpdateAIAttrib(int);
int WaveClone(int);
void WaveDelete(int);
bool WaveLoad(int, const string&);
int WaveNew(bool);
void WavePlay(int, bool = false);
void WaveSetPosition(int, const Vector3&);
void WaveStop(int);
bool WorldRayCast(const Vector3&, const Vector3&, Vector3&);
int WriteFile(int, int);
const string& GetCharName(int);
const string& GetGameVersionText();
const string& GetLevelScriptName();
const string& GetNpcScriptName(int);
const string& GetSceneScriptName();

// 类

class BufferDetail
{
public:

// 属性:
int durationMax;
int durationRest;
int resItemId;
};

class BufferDetail
{
public:

// 属性:
int durationMax;
int durationRest;
int resItemId;
};

class Color
{
public:
Color();
Color(const Color&in);
Color(float, float, float, float);
Color(float, float, float);
Color(float[]&inout);
// 方法:
Color Abs() const;
float Average() const;
float Chroma() const;
void Clip(bool);
bool Equals() const;
void FromHSL(float, float, float, float = 1.0f);
void FromHSV(float, float, float, float = 1.0f);
void FromUInt(uint);
float Hue() const;
void Invert(bool);
Color Lerp(const Color&, float) const;
float Lightness() const;
float Luma() const;
float MaxRGB() const;
float MinRGB() const;
float Range() const;
float SaturationHSL() const;
float SaturationHSV() const;
float SumRGB() const;
Vector3 ToHSL() const;
Vector3 ToHSV() const;
string ToString() const;
uint ToUInt() const;
float Value() const;

// 属性:
float a;
float b;
/* 只读 */
array<float> data;
float g;
float r;
/* 只读 */
Vector3 rgb;
/* 只读 */
Vector4 rgba;
};

class Deserializer
{
public:
// 方法:
array<uint8> Read(uint);
bool ReadBool();
int8 ReadByte();
Color ReadColor();
double ReadDouble();
string ReadFileID();
float ReadFloat();
int ReadInt();
int64 ReadInt64();
IntRect ReadIntRect();
IntVector2 ReadIntVector2();
string ReadLine();
uint ReadNetID();
Vector3 ReadPackedVector3(float);
int16 ReadShort();
string ReadString();
uint8 ReadUByte();
uint ReadUInt();
uint64 ReadUInt64();
uint16 ReadUShort();
uint ReadVLE();
Vector2 ReadVector2();
Vector3 ReadVector3();
Vector4 ReadVector4();
uint Seek(uint);
uint SeekRelative(int);
uint Tell() const;

// 属性:
/* 只读 */
uint checksum;
/* 只读 */
bool eof;
/* 只读 */
string name;
/* 只读 */
uint position;
/* 只读 */
uint size;
};

class File
{
public:
File();
File(const string&in, FileMode mode = FILE_READ);
// 方法:
void Close();
bool Open(const string&, FileMode = FILE_READ);
array<uint8> Read(uint);
bool ReadBool();
int8 ReadByte();
Color ReadColor();
double ReadDouble();
string ReadFileID();
float ReadFloat();
int ReadInt();
int64 ReadInt64();
IntRect ReadIntRect();
IntVector2 ReadIntVector2();
string ReadLine();
uint ReadNetID();
Vector3 ReadPackedVector3(float);
int16 ReadShort();
string ReadString();
uint8 ReadUByte();
uint ReadUInt();
uint64 ReadUInt64();
uint16 ReadUShort();
uint ReadVLE();
Vector2 ReadVector2();
Vector3 ReadVector3();
Vector4 ReadVector4();
uint Seek(uint);
uint SeekRelative(int);
uint Tell() const;
uint Write(array<uint8>);
bool WriteBool(bool);
bool WriteByte(int8);
bool WriteColor(const Color&);
bool WriteDouble(double);
bool WriteFileID(const string&);
bool WriteFloat(float);
bool WriteInt(int);
bool WriteInt64(int64);
bool WriteIntRect(const IntRect&);
bool WriteIntVector2(const IntVector2&);
bool WriteLine(const string&);
bool WriteNetID(uint);
bool WritePackedVector3(const Vector3&, float);
bool WriteShort(int16);
bool WriteString(const string&);
bool WriteUByte(uint8);
bool WriteUInt(uint);
bool WriteUInt64(uint64);
bool WriteUShort(uint16);
bool WriteVLE(uint);
bool WriteVector2(const Vector2&);
bool WriteVector3(const Vector3&);
bool WriteVector4(const Vector4&);

// 属性:
/* 只读 */
uint checksum;
/* 只读 */
bool eof;
/* 只读 */
FileMode mode;
/* 只读 */
string name;
/* 只读 */
bool open;
/* 只读 */
bool packaged;
/* 只读 */
uint position;
/* 只读 */
int refs;
/* 只读 */
uint size;
/* 只读 */
int weakRefs;
};

class ImFont
{
public:
ImFont();
// 方法:
bool IsValid() const;
};

class ImGuiInputTextCallbackData
{
public:
// 方法:
void DeleteChars(int, int);
bool HasSelection() const;
void InsertChars(int, const string&);

// 属性:
/* 只读 */
string Buf;
int CursorPos;
uint16 EventChar;
int EventFlag;
int EventKey;
int Flags;
int SelectionEnd;
int SelectionStart;
};

class ImGuiStyle
{
public:
ImGuiStyle();
// 方法:
Vector4 GetColor(int);
void SetColor(int, const Vector4&);

// 属性:
float Alpha;
bool AntiAliasedFill;
bool AntiAliasedLines;
Vector2 ButtonTextAlign;
float ChildBorderSize;
float ChildRounding;
float ColumnsMinSpacing;
float CurveTessellationTol;
Vector2 DisplaySafeAreaPadding;
Vector2 DisplayWindowPadding;
float FrameBorderSize;
Vector2 FramePadding;
float FrameRounding;
float GrabMinSize;
float GrabRounding;
float IndentSpacing;
Vector2 ItemInnerSpacing;
Vector2 ItemSpacing;
float MouseCursorScale;
float PopupBorderSize;
float PopupRounding;
float ScrollbarRounding;
float ScrollbarSize;
Vector2 TouchExtraPadding;
float WindowBorderSize;
Vector2 WindowMinSize;
Vector2 WindowPadding;
float WindowRounding;
Vector2 WindowTitleAlign;
};

class Image
{
public:
// 方法:
void Clear(const Color&);
void ClearInt(uint);
bool FlipHorizontal();
bool FlipVertical();
Color GetPixel(int, int) const;
Color GetPixel(int, int, int) const;
Color GetPixelBilinear(float, float) const;
uint GetPixelInt(int, int) const;
uint GetPixelInt(int, int, int) const;
Color GetPixelTrilinear(float, float, float) const;
bool Resize(int, int);
void SetPixel(int, int, const Color&);
void SetPixel(int, int, int, const Color&);
void SetPixelInt(int, int, int, uint);
void SetPixelInt(int, int, uint);
bool SetSize(int, int, int, uint);
bool SetSize(int, int, uint);

// 属性:
/* 只读 */
bool array;
/* 只读 */
uint components;
/* 只读 */
bool compressed;
/* 只读 */
CompressedFormat compressedFormat;
/* 只读 */
bool cubemap;
/* 只读 */
int depth;
/* 只读 */
bool hasAlphaChannel;
/* 只读 */
int height;
/* 只读 */
uint numCompressedLevels;
/* 只读 */
int refs;
/* 只读 */
bool sRGB;
/* 只读 */
int weakRefs;
/* 只读 */
int width;
};

class IntRect
{
public:
IntRect();
IntRect(const IntRect&in);
IntRect(int, int, int, int);
IntRect(const IntVector2&in, const IntVector2&in);
IntRect(int[]&inout);
// 方法:
int Clip(const IntRect&);
Intersection IsInside(const IntVector2&) const;
int Merge(const IntRect&);

// 属性:
int bottom;
/* 只读 */
array<int> data;
/* 只读 */
int height;
int left;
int right;
/* 只读 */
IntVector2 size;
int top;
/* 只读 */
int width;
};

class IntVector2
{
public:
IntVector2();
IntVector2(const IntVector2&in);
IntVector2(int, int);
IntVector2(int[]&inout);
// 方法:
float Length() const;
uint ToHash() const;
string ToString() const;

// 属性:
/* 只读 */
array<int> data;
int x;
int y;

// 常量:
static const IntVector2 DOWN;
static const IntVector2 LEFT;
static const IntVector2 ONE;
static const IntVector2 RIGHT;
static const IntVector2 UP;
static const IntVector2 ZERO;
};

class IntVector3
{
public:
IntVector3();
IntVector3(const IntVector3&in);
IntVector3(int, int, int);
IntVector3(int[]&inout);
// 方法:
float Length() const;
uint ToHash() const;
string ToString() const;

// 属性:
/* 只读 */
array<int> data;
int x;
int y;
int z;

// 常量:
static const IntVector3 BACK;
static const IntVector3 DOWN;
static const IntVector3 FORWARD;
static const IntVector3 LEFT;
static const IntVector3 ONE;
static const IntVector3 RIGHT;
static const IntVector3 UP;
static const IntVector3 ZERO;
};

class IntVector4
{
public:
IntVector4();
IntVector4(const IntVector4&in);
IntVector4(int, int, int, int);
IntVector4(const IntVector3&in, int);
IntVector4(int[]&inout);
// 方法:
IntVector4 Abs() const;
int AbsDotProduct(const IntVector4&) const;
int DotProduct(const IntVector4&) const;
bool Equals(const IntVector4&) const;
string ToString() const;

// 属性:
/* 只读 */
array<int> data;
int w;
int x;
int y;
int z;
};

class RefCounted
{
public:

// 属性:
/* 只读 */
int refs;
/* 只读 */
int weakRefs;
};

class Serializer
{
public:
// 方法:
uint Write(array<uint8>);
bool WriteBool(bool);
bool WriteByte(int8);
bool WriteColor(const Color&);
bool WriteDouble(double);
bool WriteFileID(const string&);
bool WriteFloat(float);
bool WriteInt(int);
bool WriteInt64(int64);
bool WriteIntRect(const IntRect&);
bool WriteIntVector2(const IntVector2&);
bool WriteLine(const string&);
bool WriteNetID(uint);
bool WritePackedVector3(const Vector3&, float);
bool WriteShort(int16);
bool WriteString(const string&);
bool WriteUByte(uint8);
bool WriteUInt(uint);
bool WriteUInt64(uint64);
bool WriteUShort(uint16);
bool WriteVLE(uint);
bool WriteVector2(const Vector2&);
bool WriteVector3(const Vector3&);
bool WriteVector4(const Vector4&);
};

class Vector2
{
public:
Vector2();
Vector2(const Vector2&in);
Vector2(const IntVector2&in);
Vector2(float, float);
Vector2(float[]&inout);
// 方法:
Vector2 Abs() const;
float AbsDotProduct(const Vector2&) const;
float Angle(const Vector2&) const;
float DotProduct(const Vector2&) const;
bool Equals(const Vector2&) const;
bool IsNaN() const;
Vector2 Lerp(const Vector2&, float) const;
void Normalize();
Vector2 Normalized() const;
float ProjectOntoAxis(const Vector2&) const;
string ToString() const;

// 属性:
/* 只读 */
array<float> data;
/* 只读 */
float length;
/* 只读 */
float lengthSquared;
float x;
float y;

// 常量:
static const Vector2 DOWN;
static const Vector2 LEFT;
static const Vector2 ONE;
static const Vector2 RIGHT;
static const Vector2 UP;
static const Vector2 ZERO;
};

class Vector3
{
public:
Vector3();
Vector3(const Vector3&in);
Vector3(const Vector2&in, float);
Vector3(const Vector2&in);
Vector3(const IntVector3&in);
Vector3(float, float, float);
Vector3(float, float);
Vector3(float[]&inout);
// 方法:
Vector3 Abs() const;
float AbsDotProduct(const Vector3&) const;
float Angle(const Vector3&) const;
Vector3 CrossProduct(const Vector3&) const;
float DistanceToPlane(const Vector3&, const Vector3&) const;
float DistanceToPoint(const Vector3&) const;
float DotProduct(const Vector3&) const;
bool Equals(const Vector3&) const;
bool IsNaN() const;
Vector3 Lerp(const Vector3&, float) const;
void Normalize();
Vector3 Normalized() const;
Vector3 Orthogonalize(const Vector3&) const;
float ProjectOntoAxis(const Vector3&) const;
Vector3 ProjectOntoLine(const Vector3&, const Vector3&, bool = false) const;
Vector3 ProjectOntoPlane(const Vector3&, const Vector3&) const;
string ToString() const;

// 属性:
/* 只读 */
array<float> data;
/* 只读 */
float length;
/* 只读 */
float lengthSquared;
float x;
float y;
float z;

// 常量:
static const Vector3 BACK;
static const Vector3 DOWN;
static const Vector3 FORWARD;
static const Vector3 LEFT;
static const Vector3 ONE;
static const Vector3 RIGHT;
static const Vector3 UP;
static const Vector3 ZERO;
};

class Vector4
{
public:
Vector4();
Vector4(const Vector4&in);
Vector4(float, float, float, float);
Vector4(const Vector3&in, float);
Vector4(float[]&inout);
// 方法:
Vector4 Abs() const;
float AbsDotProduct(const Vector4&) const;
float DotProduct(const Vector4&) const;
bool Equals(const Vector4&) const;
bool IsNaN() const;
Vector4 Lerp(const Vector4&, float) const;
float ProjectOntoAxis(const Vector3&) const;
string ToString() const;

// 属性:
/* 只读 */
array<float> data;
float w;
float x;
float y;
float z;
};

template <class T>
class array
{
public:
array(int&in);
array(int&in, uint);
array(int&in, uint, const T&in);
// 方法:
void Clear();
void Erase(uint);
int Find(const T&) const;
int Find(uint, const T&) const;
int FindByRef(const T&) const;
int FindByRef(uint, const T&) const;
uint GetSize() const;
void Insert(uint, const T&);
bool IsEmpty() const;
void Pop();
void Push(const T&);
void Reserve(uint);
void Resize(uint);
void Reverse();
void Sort();
void Sort(uint, uint);
void SortReverse();
void SortReverse(uint, uint);
bool Swap(array<T>&);

// 属性:
/* 只读 */
bool empty;
uint length;
};

class dictionary
{
public:
dictionary();
// 方法:
void Clear();
bool Erase(const string&);
bool Exists(const string&) const;
bool Get(const string&, void*) const;
bool Get(const string&, double&) const;
bool Get(const string&, int64&) const;
array<string> GetKeys() const;
uint GetSize() const;
bool IsEmpty() const;
void Set(const string&, const void*);
void Set(const string&, const double&);
void Set(const string&, const int64&);

// 属性:
/* 只读 */
bool empty;
/* 只读 */
uint length;
};

class dictionaryValue
{
public:
~dictionaryValue();
dictionaryValue();
};

class ref
{
public:
~ref();
ref();
ref(const ref&in);
ref(const ?&in);
};

class string
{
public:
~string();
string();
string(const string&in);
string(int);
string(uint);
string(float);
string(double);
string(bool);
// 方法:
void AppendUTF8(uint);
uint AtUTF8(uint) const;
uint ByteOffsetUTF8(uint) const;
void Clear();
int Compare(const string&, bool = true) const;
bool Contains(const string&, bool = true) const;
bool Contains(uint8, bool = true) const;
bool EndsWith(const string&, bool = true) const;
uint Find(const string&, uint = 0, bool = true) const;
uint Find(uint8, uint = 0, bool = true) const;
uint FindLast(const string&, uint = 0xffffffff, bool = true) const;
uint FindLast(uint8, uint = 0xffffffff, bool = true) const;
bool IsEmpty() const;
void Join(const array<string>&, const string&);
uint Length() const;
uint NextUTF8Char(uint&) const;
void Replace(const string&, const string&, bool = true);
void Replace(uint8, uint8, bool = true);
void ReplaceUTF8(uint, uint);
string Replaced(const string&, const string&, bool = true) const;
string Replaced(uint8, uint8, bool = true) const;
void Resize(uint);
void SetUTF8FromLatin1(const string&);
array<string> Split(uint8, bool = false) const;
bool StartsWith(const string&, bool = true) const;
string Substring(uint) const;
string Substring(uint, uint) const;
string SubstringUTF8(uint) const;
string SubstringUTF8(uint, uint) const;
bool ToBool() const;
double ToDouble() const;
float ToFloat() const;
int ToInt(int = 10) const;
int64 ToInt64(int = 10) const;
string ToLower() const;
uint ToUInt(int = 10) const;
uint64 ToUInt64(int = 10) const;
string ToUpper() const;
string Trimmed() const;

// 属性:
/* 只读 */
bool empty;
/* 只读 */
uint length;
/* 只读 */
uint utf8Length;

// 常量:
static const string EMPTY;
};

// 枚举值

enum CharAttrib_
{
CharAttrib_MaxHP,
CharAttrib_HP,
CharAttrib_Attack,
CharAttrib_Defense,
CharAttrib_Speed,

};

enum CharAttrib_
{
CharAttrib_MaxHP,
CharAttrib_HP,
CharAttrib_Attack,
CharAttrib_Defense,
CharAttrib_Speed,

};

enum CompressedFormat
{
CF_NONE,
CF_RGBA,
CF_DXT1,
CF_DXT3,
CF_DXT5,
CF_ETC1,
CF_PVRTC_RGB_2BPP,
CF_PVRTC_RGBA_2BPP,
CF_PVRTC_RGB_4BPP,
CF_PVRTC_RGBA_4BPP,

};

enum FileMode
{
FILE_READ,
FILE_WRITE,
FILE_READWRITE,

};

enum ImDrawCornerFlags_
{
ImDrawCornerFlags_TopLeft,
ImDrawCornerFlags_TopRight,
ImDrawCornerFlags_BotLeft,
ImDrawCornerFlags_BotRight,
ImDrawCornerFlags_Top,
ImDrawCornerFlags_Bot,
ImDrawCornerFlags_Left,
ImDrawCornerFlags_Right,
ImDrawCornerFlags_All,

};

enum ImFontGlyphRange_
{
ImFontGlyphRange_Default,
ImFontGlyphRange_Korean,
ImFontGlyphRange_Japanese,
ImFontGlyphRange_ChineseFull,
ImFontGlyphRange_ChineseSimplifiedCommon,
ImFontGlyphRange_Cyrillic,
ImFontGlyphRange_Thai,
ImFontGlyphRange_Vietnamese,

};

enum ImGuiCol_
{
ImGuiCol_Text,
ImGuiCol_TextDisabled,
ImGuiCol_WindowBg,
ImGuiCol_ChildWindowBg,
ImGuiCol_ChildBg,
ImGuiCol_PopupBg,
ImGuiCol_Border,
ImGuiCol_BorderShadow,
ImGuiCol_FrameBg,
ImGuiCol_FrameBgHovered,
ImGuiCol_FrameBgActive,
ImGuiCol_TitleBg,
ImGuiCol_TitleBgCollapsed,
ImGuiCol_TitleBgActive,
ImGuiCol_MenuBarBg,
ImGuiCol_ScrollbarBg,
ImGuiCol_ScrollbarGrab,
ImGuiCol_ScrollbarGrabHovered,
ImGuiCol_ScrollbarGrabActive,
ImGuiCol_ComboBg,
ImGuiCol_CheckMark,
ImGuiCol_SliderGrab,
ImGuiCol_SliderGrabActive,
ImGuiCol_Button,
ImGuiCol_ButtonHovered,
ImGuiCol_ButtonActive,
ImGuiCol_Header,
ImGuiCol_HeaderHovered,
ImGuiCol_HeaderActive,
ImGuiCol_Column,
ImGuiCol_ColumnHovered,
ImGuiCol_ColumnActive,
ImGuiCol_ResizeGrip,
ImGuiCol_ResizeGripHovered,
ImGuiCol_ResizeGripActive,
ImGuiCol_CloseButton,
ImGuiCol_CloseButtonHovered,
ImGuiCol_CloseButtonActive,
ImGuiCol_PlotLines,
ImGuiCol_PlotLinesHovered,
ImGuiCol_PlotHistogram,
ImGuiCol_PlotHistogramHovered,
ImGuiCol_TextSelectedBg,
ImGuiCol_ModalWindowDarkening,
ImGuiCol_COUNT,

};

enum ImGuiColorEditFlags_
{
ImGuiColorEditFlags_NoAlpha,
ImGuiColorEditFlags_NoPicker,
ImGuiColorEditFlags_NoOptions,
ImGuiColorEditFlags_NoSmallPreview,
ImGuiColorEditFlags_NoInputs,
ImGuiColorEditFlags_NoTooltip,
ImGuiColorEditFlags_NoLabel,
ImGuiColorEditFlags_NoSidePreview,
ImGuiColorEditFlags_AlphaBar,
ImGuiColorEditFlags_AlphaPreview,
ImGuiColorEditFlags_AlphaPreviewHalf,
ImGuiColorEditFlags_HDR,
ImGuiColorEditFlags_DisplayRGB,
ImGuiColorEditFlags_DisplayHSV,
ImGuiColorEditFlags_DisplayHex,
ImGuiColorEditFlags_Uint8,
ImGuiColorEditFlags_Float,
ImGuiColorEditFlags_PickerHueBar,
ImGuiColorEditFlags_PickerHueWheel,

};

enum ImGuiComboFlags_
{
ImGuiComboFlags_PopupAlignLeft,
ImGuiComboFlags_HeightSmall,
ImGuiComboFlags_HeightRegular,
ImGuiComboFlags_HeightLarge,
ImGuiComboFlags_HeightLargest,

};

enum ImGuiInputTextFlags_
{
ImGuiInputTextFlags_CharsDecimal,
ImGuiInputTextFlags_CharsHexadecimal,
ImGuiInputTextFlags_CharsUppercase,
ImGuiInputTextFlags_CharsNoBlank,
ImGuiInputTextFlags_AutoSelectAll,
ImGuiInputTextFlags_EnterReturnsTrue,
ImGuiInputTextFlags_CallbackCompletion,
ImGuiInputTextFlags_CallbackHistory,
ImGuiInputTextFlags_CallbackAlways,
ImGuiInputTextFlags_CallbackCharFilter,
ImGuiInputTextFlags_AllowTabInput,
ImGuiInputTextFlags_CtrlEnterForNewLine,
ImGuiInputTextFlags_NoHorizontalScroll,
ImGuiInputTextFlags_AlwaysInsertMode,
ImGuiInputTextFlags_ReadOnly,
ImGuiInputTextFlags_Password,
ImGuiInputTextFlags_NoUndoRedo,

};

enum ImGuiKey_
{
ImGuiKey_None,
ImGuiKey_Tab,
ImGuiKey_LeftArrow,
ImGuiKey_RightArrow,
ImGuiKey_UpArrow,
ImGuiKey_DownArrow,
ImGuiKey_PageUp,
ImGuiKey_PageDown,
ImGuiKey_Home,
ImGuiKey_End,
ImGuiKey_Insert,
ImGuiKey_Delete,
ImGuiKey_Backspace,
ImGuiKey_Space,
ImGuiKey_Enter,
ImGuiKey_Escape,
ImGuiKey_LeftCtrl,
ImGuiKey_LeftShift,
ImGuiKey_LeftAlt,
ImGuiKey_LeftSuper,
ImGuiKey_RightCtrl,
ImGuiKey_RightShift,
ImGuiKey_RightAlt,
ImGuiKey_RightSuper,
ImGuiKey_Menu,
ImGuiKey_0,
ImGuiKey_1,
ImGuiKey_2,
ImGuiKey_3,
ImGuiKey_4,
ImGuiKey_5,
ImGuiKey_6,
ImGuiKey_7,
ImGuiKey_8,
ImGuiKey_9,
ImGuiKey_A,
ImGuiKey_B,
ImGuiKey_C,
ImGuiKey_D,
ImGuiKey_E,
ImGuiKey_F,
ImGuiKey_G,
ImGuiKey_H,
ImGuiKey_I,
ImGuiKey_J,
ImGuiKey_K,
ImGuiKey_L,
ImGuiKey_M,
ImGuiKey_N,
ImGuiKey_O,
ImGuiKey_P,
ImGuiKey_Q,
ImGuiKey_R,
ImGuiKey_S,
ImGuiKey_T,
ImGuiKey_U,
ImGuiKey_V,
ImGuiKey_W,
ImGuiKey_X,
ImGuiKey_Y,
ImGuiKey_Z,
ImGuiKey_F1,
ImGuiKey_F2,
ImGuiKey_F3,
ImGuiKey_F4,
ImGuiKey_F5,
ImGuiKey_F6,
ImGuiKey_F7,
ImGuiKey_F8,
ImGuiKey_F9,
ImGuiKey_F10,
ImGuiKey_F11,
ImGuiKey_F12,
ImGuiKey_Apostrophe,
ImGuiKey_Comma,
ImGuiKey_Minus,
ImGuiKey_Period,
ImGuiKey_Slash,
ImGuiKey_Semicolon,
ImGuiKey_Equal,
ImGuiKey_LeftBracket,
ImGuiKey_Backslash,
ImGuiKey_RightBracket,
ImGuiKey_GraveAccent,
ImGuiKey_CapsLock,
ImGuiKey_ScrollLock,
ImGuiKey_NumLock,
ImGuiKey_PrintScreen,
ImGuiKey_Pause,
ImGuiKey_Keypad0,
ImGuiKey_Keypad1,
ImGuiKey_Keypad2,
ImGuiKey_Keypad3,
ImGuiKey_Keypad4,
ImGuiKey_Keypad5,
ImGuiKey_Keypad6,
ImGuiKey_Keypad7,
ImGuiKey_Keypad8,
ImGuiKey_Keypad9,
ImGuiKey_KeypadDecimal,
ImGuiKey_KeypadDivide,
ImGuiKey_KeypadMultiply,
ImGuiKey_KeypadSubtract,
ImGuiKey_KeypadAdd,
ImGuiKey_KeypadEnter,
ImGuiKey_KeypadEqual,
ImGuiKey_GamepadStart,
ImGuiKey_GamepadBack,
ImGuiKey_GamepadFaceUp,
ImGuiKey_GamepadFaceDown,
ImGuiKey_GamepadFaceLeft,
ImGuiKey_GamepadFaceRight,
ImGuiKey_GamepadDpadUp,
ImGuiKey_GamepadDpadDown,
ImGuiKey_GamepadDpadLeft,
ImGuiKey_GamepadDpadRight,
ImGuiKey_GamepadL1,
ImGuiKey_GamepadR1,
ImGuiKey_GamepadL2,
ImGuiKey_GamepadR2,
ImGuiKey_GamepadL3,
ImGuiKey_GamepadR3,
ImGuiKey_GamepadLStickUp,
ImGuiKey_GamepadLStickDown,
ImGuiKey_GamepadLStickLeft,
ImGuiKey_GamepadLStickRight,
ImGuiKey_GamepadRStickUp,
ImGuiKey_GamepadRStickDown,
ImGuiKey_GamepadRStickLeft,
ImGuiKey_GamepadRStickRight,
ImGuiKey_ModCtrl,
ImGuiKey_ModShift,
ImGuiKey_ModAlt,
ImGuiKey_ModSuper,
ImGuiKey_COUNT,

};

enum ImGuiSelectableFlags_
{
ImGuiSelectableFlags_DontClosePopups,
ImGuiSelectableFlags_SpanAllColumns,
ImGuiSelectableFlags_AllowDoubleClick,

};

enum ImGuiSetCond_
{
ImGuiCond_Always,
ImGuiCond_Once,
ImGuiCond_FirstUseEver,
ImGuiCond_Appearing,
ImGuiSetCond_Always,
ImGuiSetCond_Once,
ImGuiSetCond_FirstUseEver,
ImGuiSetCond_Appearing,

};

enum ImGuiStyleVar_
{
ImGuiStyleVar_Alpha,
ImGuiStyleVar_DisabledAlpha,
ImGuiStyleVar_WindowPadding,
ImGuiStyleVar_WindowRounding,
ImGuiStyleVar_WindowBorderSize,
ImGuiStyleVar_WindowMinSize,
ImGuiStyleVar_WindowTitleAlign,
ImGuiStyleVar_ChildRounding,
ImGuiStyleVar_ChildBorderSize,
ImGuiStyleVar_PopupRounding,
ImGuiStyleVar_PopupBorderSize,
ImGuiStyleVar_FramePadding,
ImGuiStyleVar_FrameRounding,
ImGuiStyleVar_FrameBorderSize,
ImGuiStyleVar_ItemSpacing,
ImGuiStyleVar_ItemInnerSpacing,
ImGuiStyleVar_IndentSpacing,
ImGuiStyleVar_CellPadding,
ImGuiStyleVar_ScrollbarSize,
ImGuiStyleVar_ScrollbarRounding,
ImGuiStyleVar_GrabMinSize,
ImGuiStyleVar_GrabRounding,
ImGuiStyleVar_TabRounding,
ImGuiStyleVar_ButtonTextAlign,
ImGuiStyleVar_SelectableTextAlign,
ImGuiStyleVar_Count_,

};

enum ImGuiTreeNodeFlags_
{
ImGuiTreeNodeFlags_Selected,
ImGuiTreeNodeFlags_Framed,
ImGuiTreeNodeFlags_AllowOverlapMode,
ImGuiTreeNodeFlags_AllowItemOverlap,
ImGuiTreeNodeFlags_NoTreePushOnOpen,
ImGuiTreeNodeFlags_NoAutoOpenOnLog,
ImGuiTreeNodeFlags_DefaultOpen,
ImGuiTreeNodeFlags_OpenOnDoubleClick,
ImGuiTreeNodeFlags_OpenOnArrow,
ImGuiTreeNodeFlags_Leaf,
ImGuiTreeNodeFlags_Bullet,
ImGuiTreeNodeFlags_FramePadding,
ImGuiTreeNodeFlags_CollapsingHeader,

};

enum ImGuiWindowFlags_
{
ImGuiWindowFlags_NoTitleBar,
ImGuiWindowFlags_NoResize,
ImGuiWindowFlags_NoMove,
ImGuiWindowFlags_NoScrollbar,
ImGuiWindowFlags_NoScrollWithMouse,
ImGuiWindowFlags_NoCollapse,
ImGuiWindowFlags_AlwaysAutoResize,
ImGuiWindowFlags_NoBackground,
ImGuiWindowFlags_NoSavedSettings,
ImGuiWindowFlags_NoMouseInputs,
ImGuiWindowFlags_MenuBar,
ImGuiWindowFlags_HorizontalScrollbar,
ImGuiWindowFlags_NoFocusOnAppearing,
ImGuiWindowFlags_NoBringToFrontOnFocus,
ImGuiWindowFlags_AlwaysVerticalScrollbar,
ImGuiWindowFlags_AlwaysHorizontalScrollbar,
ImGuiWindowFlags_AlwaysUseWindowPadding,
ImGuiWindowFlags_NoNavInputs,
ImGuiWindowFlags_NoNavFocus,
ImGuiWindowFlags_UnsavedDocument,
ImGuiWindowFlags_NoNav,
ImGuiWindowFlags_NoDecoration,
ImGuiWindowFlags_NoInputs,

};

enum Intersection
{
OUTSIDE,
INTERSECTS,
INSIDE,

};

// 全局函数
float Abs(float);
float Acos(float);
string AddTrailingSlash(const string&);
float Asin(float);
float Atan(float);
float Atan2(float, float);
float Ceil(float);
int CeilToInt(float);
float Clamp(float, float, float);
int Clamp(int, int, int);
float Cos(float);
uint CountSetBits(uint);
bool Equals(float, float);
float Floor(float);
int FloorToInt(float);
float Fract(float);
string GetExtension(const string&, bool = true);
string GetFileName(const string&);
string GetFileNameAndExtension(const string&, bool = false);
string GetFileSizeString(uint64);
string GetInternalPath(const string&);
string GetParentPath(const string&);
string GetPath(const string&);
uint GetRandomSeed();
int GetTeam(int);
void ImDrawList_AddBezierCurve(const Vector2&, const Vector2&, const Vector2&, const Vector2&, uint, float, int = 0);
void ImDrawList_AddCircle(const Vector2&, float, uint, int = 12, float = 1.0f);
void ImDrawList_AddCircleFilled(const Vector2&, float, uint, int = 12);
void ImDrawList_AddImage(Image, const Vector2&, const Vector2&, const Vector2& = Vector2 ( 0 , 0 ), const Vector2& = Vector2 ( 1 , 1 ), uint = 0xFFFFFFFF);
void ImDrawList_AddImageQuad(Image, const Vector2&, const Vector2&, const Vector2&, const Vector2&, const Vector2& = Vector2 ( 0 , 0 ), const Vector2& = Vector2 ( 1 , 0 ), const Vector2& = Vector2 ( 1 , 1 ), const Vector2& = Vector2 ( 0 , 1 ), uint = 0xFFFFFFFF);
void ImDrawList_AddImageRounded(Image, const Vector2&, const Vector2&, const Vector2&, const Vector2&, uint, float, int = 0xF);
void ImDrawList_AddLine(const Vector2&, const Vector2&, uint, float = 1.0f);
void ImDrawList_AddQuad(const Vector2&, const Vector2&, const Vector2&, const Vector2&, uint, float = 1.0f);
void ImDrawList_AddQuadFilled(const Vector2&, const Vector2&, const Vector2&, const Vector2&, uint);
void ImDrawList_AddRect(const Vector2&, const Vector2&, uint, float = 0.0f, int = 0xF, float = 1.0f);
void ImDrawList_AddRectFilled(const Vector2&, const Vector2&, uint, float = 0.0f, int = 0xF);
void ImDrawList_AddRectFilledMultiColor(const Vector2&, const Vector2&, uint, uint, uint, uint);
void ImDrawList_AddText(const Vector2&, uint, const string&);
void ImDrawList_AddTriangle(const Vector2&, const Vector2&, const Vector2&, uint, float = 1.0f);
void ImDrawList_AddTriangleFilled(const Vector2&, const Vector2&, const Vector2&, uint);
void ImDrawList_PathArcTo(const Vector2&, float, float, float, int = 10);
void ImDrawList_PathArcToFast(const Vector2&, float, int, int);
void ImDrawList_PathBezierCurveTo(const Vector2&, const Vector2&, const Vector2&, int = 0);
void ImDrawList_PathClear();
void ImDrawList_PathFillConvex(uint);
void ImDrawList_PathLineTo(const Vector2&);
void ImDrawList_PathLineToMergeDuplicate(const Vector2&);
void ImDrawList_PathRect(const Vector2&, const Vector2&, float = 0.0f, int = 0xF);
void ImDrawList_PathStroke(uint, bool, float = 1.0f);
void ImGui_AlignFirstTextHeightToWidgets();
void ImGui_AlignTextToFramePadding();
bool ImGui_Begin(const string&, bool&, int = 0);
bool ImGui_Begin(const string&, int = 0);
bool ImGui_BeginChild(const string&, const Vector2& = Vector2 ( 0 , 0 ), bool = false, int = 0);
bool ImGui_BeginChild(uint, const Vector2& = Vector2 ( 0 , 0 ), bool = false, int = 0);
bool ImGui_BeginChildFrame(uint, const Vector2&, int = 0);
bool ImGui_BeginCombo(const string&, const string&, int = 0);
void ImGui_BeginDisabled(bool);
void ImGui_BeginGroup();
bool ImGui_BeginMenu(const string&, bool = true);
bool ImGui_BeginMenuBar();
bool ImGui_BeginPopup(const string&);
bool ImGui_BeginPopupContextItem(const string& = string ( ), int = 1);
bool ImGui_BeginPopupContextVoid(const string&, int = 1);
bool ImGui_BeginPopupContextVoid(int = 1);
bool ImGui_BeginPopupContextWindow(bool = true, int = 1);
bool ImGui_BeginPopupContextWindow(bool, const string&, int = 1);
bool ImGui_BeginPopupModal(const string&, bool&, int = 0);
bool ImGui_BeginPopupModal(const string&, int = 0);
void ImGui_BeginTooltip();
void ImGui_Bullet();
void ImGui_BulletText(const string&);
bool ImGui_Button(const string&, const Vector2& = Vector2 ( 0 , 0 ));
float ImGui_CalcItemWidth();
void ImGui_CalcListClipping(int, float, int&, int&);
Vector2 ImGui_CalcTextSize(const string&, bool = false, float = - 1.0f);
void ImGui_CaptureKeyboardFromApp(bool = true);
void ImGui_CaptureMouseFromApp(bool = true);
bool ImGui_Checkbox(const string&, bool&);
bool ImGui_CheckboxFlags(const string&, uint&, uint);
void ImGui_CloseCurrentPopup();
bool ImGui_CollapsingHeader(const string&, bool&, int = 0);
bool ImGui_CollapsingHeader(const string&, int = 0);
bool ImGui_ColorButton(const Vector4&, bool = false, bool = true);
bool ImGui_ColorButton(const string&, const Vector4&, int = 0, const Vector2& = Vector2 ( 0 , 0 ));
uint ImGui_ColorConvertFloat4ToU32(const Vector4&);
void ImGui_ColorConvertHSVtoRGB(float, float, float, float&, float&, float&);
void ImGui_ColorConvertRGBtoHSV(float, float, float, float&, float&, float&);
Vector4 ImGui_ColorConvertU32ToFloat4(uint);
bool ImGui_ColorEdit3(const string&, Vector3&, int = 0);
bool ImGui_ColorEdit4(const string&, Vector4&, bool = true);
bool ImGui_ColorEdit4(const string&, Vector4&, int);
bool ImGui_ColorPicker3(const string&, Vector3&, int = 0);
bool ImGui_ColorPicker4(const string&, Vector4&, int = 0);
bool ImGui_ColorPicker4(const string&, Vector4&, int, Vector4);
bool ImGui_Columns(int = 1, bool = true);
bool ImGui_Columns(int, const string&, bool = true);
bool ImGui_Combo(const string&, int&, const string&, int = - 1);
bool ImGui_Combo(const string&, int&, const array<string>&, int = - 1);
bool ImGui_DragFloat(const string&, float&, float = 1.0f, float = 0.0f, float = 0.0f, const string& = "%.3f", float = 1.0f);
bool ImGui_DragFloat2(const string&, Vector2&, float = 1.0f, float = 0.0f, float = 0.0f, const string& = "%.3f", float = 1.0f);
bool ImGui_DragFloat3(const string&, Vector3&, float = 1.0f, float = 0.0f, float = 0.0f, const string& = "%.3f", float = 1.0f);
bool ImGui_DragFloat4(const string&, Vector4&, float = 1.0f, float = 0.0f, float = 0.0f, const string& = "%.3f", float = 1.0f);
bool ImGui_DragFloatRange2(const string&, float&, float&, float = 1.0f, float = 0.0f, float = 0.0f, const string& = "%.3f");
bool ImGui_DragInt(const string&, int&, float = 1.0f, int = 0, int = 0, const string& = "%.0f");
bool ImGui_DragInt2(const string&, IntVector2&, float = 1.0f, int = 0, int = 0, const string& = "%.0f");
bool ImGui_DragInt3(const string&, IntVector3&, float = 1.0f, int = 0, int = 0, const string& = "%.0f");
bool ImGui_DragInt4(const string&, IntVector4&, float = 1.0f, int = 0, int = 0, const string& = "%.0f");
bool ImGui_DragIntRange2(const string&, int&, int&, float = 1.0f, int = 0.0f, int = 0.0f, const string& = "%.3f");
bool ImGui_DragIntRange2(const string&, int&, int&, float, int, int, const string&, const string&);
void ImGui_Dummy(const Vector2&);
void ImGui_End();
void ImGui_EndChild();
void ImGui_EndChildFrame();
void ImGui_EndCombo();
void ImGui_EndDisabled();
void ImGui_EndGroup();
void ImGui_EndMenu();
void ImGui_EndMenuBar();
void ImGui_EndPopup();
void ImGui_EndTooltip();
string ImGui_GetClipboardText();
uint ImGui_GetColorU32(uint, float = 1.0f);
int ImGui_GetColumnIndex();
float ImGui_GetColumnOffset(int = - 1);
float ImGui_GetColumnWidth(int = - 1);
int ImGui_GetColumnsCount();
Vector2 ImGui_GetContentRegionAvail();
Vector2 ImGui_GetContentRegionMax();
Vector2 ImGui_GetCursorPos();
float ImGui_GetCursorPosX();
float ImGui_GetCursorPosY();
Vector2 ImGui_GetCursorScreenPos();
Vector2 ImGui_GetCursorStartPos();
Vector2 ImGui_GetDisplaySize();
int ImGui_GetFrameCount();
float ImGui_GetFrameHeight();
float ImGui_GetFrameHeightWithSpacing();
uint ImGui_GetID(const void*);
uint ImGui_GetID(const string&);
Vector2 ImGui_GetItemRectMax();
Vector2 ImGui_GetItemRectMin();
Vector2 ImGui_GetItemRectSize();
float ImGui_GetItemsLineHeightWithSpacing();
int ImGui_GetKeyIndex(int);
int ImGui_GetMouseCursor();
Vector2 ImGui_GetMouseDragDelta(int = 0, float = - 1.0f);
Vector2 ImGui_GetMousePos();
Vector2 ImGui_GetMousePosOnOpeningCurrentPopup();
float ImGui_GetScrollMaxX();
float ImGui_GetScrollMaxY();
float ImGui_GetScrollX();
float ImGui_GetScrollY();
ImGuiStyle& ImGui_GetStyle();
string ImGui_GetStyleColName(int);
string ImGui_GetStyleColorName(int);
Vector4 ImGui_GetStyleColorVec4(int);
float ImGui_GetTextLineHeight();
float ImGui_GetTextLineHeightWithSpacing();
float ImGui_GetTime();
float ImGui_GetTreeNodeToLabelSpacing();
Vector2 ImGui_GetWindowContentRegionMax();
Vector2 ImGui_GetWindowContentRegionMin();
float ImGui_GetWindowContentRegionWidth();
float ImGui_GetWindowHeight();
Vector2 ImGui_GetWindowPos();
Vector2 ImGui_GetWindowSize();
float ImGui_GetWindowWidth();
void ImGui_Image(Image, const Vector2&, const Vector2& = Vector2 ( 0 , 0 ), const Vector2& = Vector2 ( 1 , 1 ), const Vector4& = Vector4 ( 1 , 1 , 1 , 1 ), const Vector4& = Vector4 ( 0 , 0 , 0 , 0 ));
bool ImGui_ImageButton(Image, const Vector2&, const Vector2& = Vector2 ( 0 , 0 ), const Vector2& = Vector2 ( 1 , 1 ), int = - 1, const Vector4& = Vector4 ( 0 , 0 , 0 , 0 ), const Vector4& = Vector4 ( 1 , 1 , 1 , 1 ));
void ImGui_Indent(float = 0.0f);
bool ImGui_InputFloat(const string&, float&, float = 0.0f, float = 0.0f, int = - 1, int = 0);
bool ImGui_InputFloat2(const string&, Vector2&, int = - 1, int = 0);
bool ImGui_InputFloat3(const string&, Vector3&, int = - 1, int = 0);
bool ImGui_InputFloat4(const string&, Vector4&, int = - 1, int = 0);
bool ImGui_InputInt(const string&, int&, int = 1, int = 100, int = 0);
bool ImGui_InputText(const string&, string&, int = 0, const ImGuiInputTextCallback = null);
bool ImGui_InputTextMultiline(const string&, const Vector2& = Vector2 ( 0 , 0 ), int = 0);
bool ImGui_InputTextMultiline(const string&, string&, int, const Vector2& = Vector2 ( 0 , 0 ), int = 0);
bool ImGui_InvisibleButton(const string&, const Vector2&);
bool ImGui_IsAnyItemActive();
bool ImGui_IsAnyItemHovered();
bool ImGui_IsItemActive();
bool ImGui_IsItemClicked(int = 0);
bool ImGui_IsItemHovered();
bool ImGui_IsItemHoveredRect();
bool ImGui_IsItemVisible();
bool ImGui_IsKeyDown(int);
bool ImGui_IsKeyPressed(int, bool = true);
bool ImGui_IsKeyReleased(int);
bool ImGui_IsMouseClicked(int, bool = false);
bool ImGui_IsMouseDoubleClicked(int);
bool ImGui_IsMouseDown(int);
bool ImGui_IsMouseDragging(int = 0, float = - 1.0f);
bool ImGui_IsMouseHoveringAnyWindow();
bool ImGui_IsMouseHoveringRect(const Vector2&, const Vector2&, bool = true);
bool ImGui_IsMouseHoveringWindow();
bool ImGui_IsMouseReleased(int);
bool ImGui_IsPopupOpen(const string&);
bool ImGui_IsRectVisible(const Vector2&);
bool ImGui_IsRectVisible(const Vector2&, const Vector2&);
bool ImGui_IsRootWindowFocused();
bool ImGui_IsRootWindowOrAnyChildFocused();
bool ImGui_IsRootWindowOrAnyChildHovered();
bool ImGui_IsWindowAppearing();
bool ImGui_IsWindowCollapsed();
bool ImGui_IsWindowFocused();
bool ImGui_IsWindowHovered();
void ImGui_LabelText(const string&, const string&);
void ImGui_ListBoxFooter();
bool ImGui_ListBoxHeader(const string&);
bool ImGui_ListBoxHeader(const string&, const Vector2&);
bool ImGui_ListBoxHeader(const string&, int, int = - 1);
void ImGui_LogButtons();
void ImGui_LogFinish();
void ImGui_LogText(const string&);
void ImGui_LogToClipboard(int = - 1);
bool ImGui_MenuItem(const string&, bool = false, bool = true);
void ImGui_NewLine();
bool ImGui_NextColumn();
void ImGui_OpenPopup(const string&);
void ImGui_OpenPopupOnItemClick(const string&, int = 1);
void ImGui_PopAllowKeyboardFocus();
void ImGui_PopButtonRepeat();
void ImGui_PopID();
void ImGui_PopItemWidth();
void ImGui_PopStyleColor(int = 1);
void ImGui_PopStyleVar(int = 1);
void ImGui_PopTextWrapPos();
void ImGui_PushAllowKeyboardFocus(bool);
void ImGui_PushButtonRepeat(bool);
void ImGui_PushID(const void*);
void ImGui_PushID(const string&);
void ImGui_PushID(int);
void ImGui_PushItemWidth(float);
void ImGui_PushStyleColor(int, const Vector4&);
void ImGui_PushStyleVar(int, bool);
void ImGui_PushStyleVar(int, const Vector2&);
void ImGui_PushStyleVar(int, float);
void ImGui_PushStyleVar(int, int);
void ImGui_PushTextWrapPos(float = 0.0f);
bool ImGui_RadioButton(const string&, bool);
bool ImGui_RadioButton(const string&, int&, int);
void ImGui_ResetMouseDragDelta(int = 0);
void ImGui_SameLine(float = 0.0, float = - 1.0);
bool ImGui_Selectable(const string&, bool = false, int = 0, const Vector2& = Vector2 ( 0 , 0 ));
bool ImGui_SelectableToggle(const string&, bool&, int = 0, const Vector2& = Vector2 ( 0 , 0 ));
void ImGui_Separator();
void ImGui_SetClipboardText(const string&);
void ImGui_SetColumnOffset(int, float);
float ImGui_SetColumnWidth(int, float);
void ImGui_SetCursorPos(const Vector2&);
void ImGui_SetCursorPosX(float);
void ImGui_SetCursorPosY(float);
void ImGui_SetCursorScreenPos(const Vector2&);
void ImGui_SetItemAllowOverlap();
void ImGui_SetItemDefaultFocus();
void ImGui_SetKeyboardFocusHere(int = 0);
void ImGui_SetMouseCursor(int);
void ImGui_SetNextWindowCollapsed(bool, int = 0);
void ImGui_SetNextWindowContentSize(const Vector2&);
void ImGui_SetNextWindowContentWidth(float);
void ImGui_SetNextWindowFocus();
void ImGui_SetNextWindowPos(const Vector2&, int = 0);
void ImGui_SetNextWindowPosCenter(int = 0);
void ImGui_SetNextWindowSize(const Vector2&, int = 0);
void ImGui_SetScrollFromPosY(float, float = 0.5f);
void ImGui_SetScrollHereY(float = 0.5f);
void ImGui_SetScrollX(float);
void ImGui_SetScrollY(float);
void ImGui_SetTooltip(const string&);
void ImGui_SetWindowCollapsed(bool, int = 0);
void ImGui_SetWindowCollapsed(const string&, bool, int = 0);
void ImGui_SetWindowFocus();
void ImGui_SetWindowFocus(const string&);
void ImGui_SetWindowFontScale(float);
void ImGui_SetWindowPos(const Vector2&, int = 0);
void ImGui_SetWindowPos(const string&, const Vector2&, int = 0);
void ImGui_SetWindowSize(const Vector2&, int = 0);
void ImGui_SetWindowSize(const string&, const Vector2&, int = 0);
bool ImGui_SliderAngle(const string&, float&, float = - 360.0f, float = + 360.0f);
bool ImGui_SliderFloat(const string&, float&, float, float, const string& = "%.3f", float = 1.0f);
bool ImGui_SliderFloat2(const string&, Vector2&, float, float, const string& = "%.3f", float = 1.0f);
bool ImGui_SliderFloat3(const string&, Vector3&, float, float, const string& = "%.3f", float = 1.0f);
bool ImGui_SliderFloat4(const string&, Vector4&, float, float, const string& = "%.3f", float = 1.0f);
bool ImGui_SliderInt(const string&, int&, int, int, const string& = "%.0f");
bool ImGui_SliderInt2(const string&, IntVector2&, int, int, const string& = "%.0f");
bool ImGui_SliderInt3(const string&, IntVector3&, int, int, const string& = "%.0f");
bool ImGui_SliderInt4(const string&, IntVector4&, int, int, const string& = "%.0f");
bool ImGui_SmallButton(const string&);
void ImGui_Spacing();
void ImGui_Text(const string&);
void ImGui_TextColored(const Vector4&, const string&);
void ImGui_TextDisabled(const string&);
void ImGui_TextWrapped(const string&);
bool ImGui_TreeNode(const void*, const string&);
bool ImGui_TreeNode(const string&);
bool ImGui_TreeNode(const string&, const string&);
bool ImGui_TreeNodeEx(const void*, int, const string&);
bool ImGui_TreeNodeEx(const string&, int = 0);
bool ImGui_TreeNodeEx(const string&, int, const string&);
void ImGui_TreePop();
void ImGui_TreePush();
void ImGui_TreePush(const void*);
void ImGui_TreePush(const string&);
void ImGui_Unindent(float = 0.0f);
bool ImGui_WantCaptureMouse();
float InverseLerp(float, float, float);
bool IsAbsolutePath(const string&);
bool IsAlpha(uint);
bool IsDigit(uint);
bool IsNaN(double);
bool IsNaN(float);
bool IsPowerOfTwo(uint);
string Join(const array<string>&, const string&);
float Lerp(float, float, float);
bool ListBox(const string&, int&, const ImGuiItemGetter, int, int = - 1);
float Ln(float);
uint LogBaseTwo(uint);
float Max(float, float);
int Max(int, int);
float Min(float, float);
int Min(int, int);
float Mod(float, float);
uint NextPowerOfTwo(uint);
float Pow(float, float);
float Random();
float Random(float);
float Random(float, float);
int RandomInt();
int RandomInt(int);
int RandomInt(int, int);
float RandomNormal(float, float);
string RemoveTrailingSlash(const string&);
string ReplaceExtension(const string&, const string&);
float Round(float);
int RoundToInt(float);
uint SDBMHash(uint, uint8);
array<string> ScanDir(const string&, const string&, uint, bool);
void SetRandomSeed(uint);
float Sign(float);
float Sin(float);
float SmoothStep(float, float, float);
float Sqrt(float);
float StableRandom(const Vector2&);
float StableRandom(const Vector3&);
float StableRandom(float);
int Strcmp(const string&, const string&);
int Stricmp(const string&, const string&);
int Strncmp(const string&, const string&, int);
int Strnicmp(const string&, const string&, int);
float Tan(float);
uint ToLower(uint);
string ToStringHex(int);
uint ToUpper(uint);
IntVector4 VectorCeil(const IntVector4&);
Vector2 VectorCeil(const Vector2&);
Vector3 VectorCeil(const Vector3&);
Vector4 VectorCeil(const Vector4&);
IntVector2 VectorCeilToInt(const Vector2&);
IntVector3 VectorCeilToInt(const Vector3&);
IntVector4 VectorFloor(const IntVector4&);
Vector2 VectorFloor(const Vector2&);
Vector3 VectorFloor(const Vector3&);
Vector4 VectorFloor(const Vector4&);
IntVector2 VectorFloorToInt(const Vector2&);
IntVector3 VectorFloorToInt(const Vector3&);
IntVector4 VectorLerp(const IntVector4&, const IntVector4&, const IntVector4&);
Vector2 VectorLerp(const Vector2&, const Vector2&, const Vector2&);
Vector3 VectorLerp(const Vector3&, const Vector3&, const Vector3&);
Vector4 VectorLerp(const Vector4&, const Vector4&, const Vector4&);
IntVector2 VectorMax(const IntVector2&, const IntVector2&);
IntVector3 VectorMax(const IntVector3&, const IntVector3&);
IntVector4 VectorMax(const IntVector4&, const IntVector4&);
Vector2 VectorMax(const Vector2&, const Vector2&);
Vector3 VectorMax(const Vector3&, const Vector3&);
Vector4 VectorMax(const Vector4&, const Vector4&);
IntVector2 VectorMin(const IntVector2&, const IntVector2&);
IntVector3 VectorMin(const IntVector3&, const IntVector3&);
IntVector4 VectorMin(const IntVector4&, const IntVector4&);
Vector2 VectorMin(const Vector2&, const Vector2&);
Vector3 VectorMin(const Vector3&, const Vector3&);
Vector4 VectorMin(const Vector4&, const Vector4&);
IntVector4 VectorRound(const IntVector4&);
Vector2 VectorRound(const Vector2&);
Vector3 VectorRound(const Vector3&);
Vector4 VectorRound(const Vector4&);
IntVector2 VectorRoundToInt(const Vector2&);
IntVector3 VectorRoundToInt(const Vector3&);

// 全局属性

// 全局常量
Color BLACK;
Color BLUE;
Color CYAN;
Color GRAY;
Color GREEN;
Color MAGENTA;
float M_DEGTORAD;
float M_DEGTORAD_2;
float M_EPSILON;
float M_HALF_PI;
float M_INFINITY;
float M_LARGE_EPSILON;
float M_LARGE_VALUE;
int M_MAX_INT;
uint M_MAX_UNSIGNED;
int M_MIN_INT;
uint M_MIN_UNSIGNED;
float M_PI;
float M_RADTODEG;
uint NPOS;
Color RED;
uint SCAN_DIRS;
uint SCAN_FILES;
uint SCAN_HIDDEN;
Color TRANSPARENT_BLACK;
Color WHITE;
Color YELLOW;
