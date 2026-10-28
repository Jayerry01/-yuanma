funcdef void FuncDef_AsSceneItemOnTouch(AsSceneItem@ item, int charId);
funcdef void FuncDef_AsSceneItemOnPickUp(AsSceneItem@ item, int charId);
funcdef void FuncDef_AsSceneItemOnAttack(AsSceneItem@ item, int charId, int damage);
funcdef void FuncDef_AsSceneItemOnIdle(AsSceneItem@ item);

AsSceneItem@[] g_asSceneItemList;

void AsDispatchOnTouchForAsSceneItemList(int id, int charId){
    auto size = g_asSceneItemList.GetSize();
    for (uint i = 0; i < size; i++){
        AsSceneItem@ item = g_asSceneItemList[i];
        if (item.Id == id){
            auto handlerCount = item._onTouchList.GetSize();
            for (uint j = 0; j < handlerCount; j++){
                item._onTouchList[j](item, charId);
            }
        }
    }
}

void AsDispatchOnPickUpForAsSceneItemList(int id, int charId){
    auto size = g_asSceneItemList.GetSize();
    for (uint i = 0; i < size; i++){
        AsSceneItem@ item = g_asSceneItemList[i];
        if (item.Id == id){
            auto handlerCount = item._onPickUpList.GetSize();
            for (uint j = 0; j < handlerCount; j++){
                item._onPickUpList[j](item, charId);
            }
        }
    }
}

void AsDispatchOnAttackForAsSceneItemList(int id, int charId, int damage){
    auto size = g_asSceneItemList.GetSize();
    for (uint i = 0; i < size; i++){
        AsSceneItem@ item = g_asSceneItemList[i];
        if (item.Id == id){
            auto handlerCount = item._onAttackList.GetSize();
            for (uint j = 0; j < handlerCount; j++){
                item._onAttackList[j](item, charId, damage);
            }
        }
    }
}

void AsDispatchOnIdleForAsSceneItemList(int id){
    auto size = g_asSceneItemList.GetSize();
    for (uint i = 0; i < size; i++){
        AsSceneItem@ item = g_asSceneItemList[i];
        if (item.Id == id){
            auto handlerCount = item._onIdleList.GetSize();
            for (uint j = 0; j < handlerCount; j++){
                item._onIdleList[j](item);
            }
        }
    }
}

class AsSceneItem{
    AsSceneItem(string model){
        auto uniqueId = g_asSceneItemList.GetSize();
        string name = "E" + uniqueId + "_" + model;
        _id = CreateSceneItem(name, "", model);
        if (_id<0){
            Print("创建道具", name,  "失败");
        }
        g_asSceneItemList.Push(this);
    }

    Vector3 Position{
        get const{
            return GetSceneItemPosition(_id);
        }
        set{
            SetSceneItemPosition(_id, value);
        }
    }

    float YawAngle{
        get const{
            return GetSceneItemRotationYaw(_id);
        }
        set{
            SetSceneItemRotationYaw(_id, value);
        }
    }
    string ItemType{
        set{
            SetSceneItem(_id, "name", value);
        }
    }

    string Name{
        get const{
            return GetSceneItemName(_id);
        }
    }


    int Pose{
        get const{
            return GetSceneItem(_id, "pose");
        }
        set{
            _pose = value;
            SetSceneItem(_id, "pose", _pose, _isLoop);
        }
    }

    bool IsLoop {
        get const{
            return _isLoop;
        }
        set {
            _isLoop = value;
            SetSceneItem(_id, "pose", _pose, _isLoop);
        }
    }

    int Frame{
        set{
            SetSceneItem(_id, "frame", value);
        }
    }

    int Id{
        get const{
            return _id;
        }
    }

    int Active{
        set{
            SetSceneItem(_id, "attribute", "active", value);
        }
    }

    int Interactive{
        set{
            SetSceneItem(_id, "attribute", "interactive", value);
        }
    }
    

    int Collision{
        set{
            SetSceneItem(_id, "attribute", "collision", value);
        }
    }

    int Visible{
        set{
            SetSceneItem(_id, "attribute", "visible", value);
        }
    }

    int Damage{
        set{
            SetSceneItem(_id, "attribute", "damage", value);
        }
    }

    int DamageValue{
        set{
            SetSceneItem(_id, "attribute", "damagevalue", value);
        }
    }

    int Reborn{
        set{
            SetSceneItem(_id, "attribute", "reborn", value);
        }
    }


    int State{
        get const{
            return GetSceneItem(_id, "state");
        }
        set{
            SetSceneItem(_id, "state", value);
        }
    }

    void CreateEffect(string effect){
        ::CreateEffect(_id, effect);
    }

    void AddHandlerOnTouch(FuncDef_AsSceneItemOnTouch@ OnTouch){
        _onTouchList.Push(OnTouch);
    }
    void AddHandlerOnPickUp(FuncDef_AsSceneItemOnPickUp@ OnPickUp){
        _onPickUpList.Push(OnPickUp);
    }
    void AddHandlerOnAttack(FuncDef_AsSceneItemOnAttack@ OnAttack){
        _onAttackList.Push(OnAttack);
    }
    void AddHandlerOnIdle(FuncDef_AsSceneItemOnIdle@ OnIdle){
        _onIdleList.Push(OnIdle);
    }

    private int _id = -1;
    private int _pose = 0;
    private bool _isLoop = false;
    FuncDef_AsSceneItemOnTouch@[] _onTouchList;
    FuncDef_AsSceneItemOnPickUp@[] _onPickUpList;
    FuncDef_AsSceneItemOnAttack@[] _onAttackList;
    FuncDef_AsSceneItemOnIdle@[] _onIdleList;
}
