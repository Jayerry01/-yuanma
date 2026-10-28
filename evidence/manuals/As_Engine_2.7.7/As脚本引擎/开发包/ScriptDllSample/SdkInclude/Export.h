#pragma once

#if defined(ScriptEngine_EXPORTS)
#   define SCRIPTENGINE_API __declspec(dllexport)
#   define URHO3D_API __declspec(dllexport)
#   define AS_API __declspec(dllexport)
#else
#   define SCRIPTENGINE_API
#   define URHO3D_API
#   define AS_API
#endif

class asIScriptContext;
class asIScriptEngine;

namespace Urho3D {
    class String;
}

using AsString = Urho3D::String;

using ExternalDllRegisterScriptApiProc = void(*)(asIScriptEngine* asEngine, const AsString& gameversionText);

// 获取AngelScript活动上下文
SCRIPTENGINE_API asIScriptContext* AsGetActiveContext();

// 判断当前游戏是否在关卡内
SCRIPTENGINE_API bool IsInLevel();

// 判断当前游戏是否在场景内
SCRIPTENGINE_API bool IsInScene();