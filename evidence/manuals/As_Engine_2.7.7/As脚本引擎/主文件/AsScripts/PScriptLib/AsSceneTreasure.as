#include "AsSceneItem.as"
#include "AsSceneBreakControl.as"

// 场景宝藏
class AsSceneTreasure{
    AsSceneBreakControl Control;

    private AsSceneItem@ _container;
    private AsSceneItem@ _hiddenItem;
    AsSceneTreasure(string containerNodel, string itemModel) {
        @_container = AsSceneItem(containerNodel);
        @_hiddenItem = AsSceneItem(itemModel);

        @Control.BreakableItem = _container;
        @Control.OnInit = FuncDefAction(OnControlInit);
        @Control.OnBreak = FuncDefAction(OnControlBreak);
        Control.Bind();
    }

    Vector3 ContainerPosition{
        get const{
            return _container.Position;
        }
        set{
            _container.Position = value;
        }
    }

    Vector3 ItemPosition{
        get const{
            return _hiddenItem.Position;
        }
        set{
            _hiddenItem.Position = value;
        }
    }

    float ContainerYawAngle{
        get const{
            return _container.YawAngle;
        }
        set{
            _container.YawAngle = value;
        }
    }

    float ItemYawAngle{
        get const{
            return _hiddenItem.YawAngle;
        }
        set{
            _hiddenItem.YawAngle = value;
        }
    }

    void OnControlInit(){
        _hiddenItem.ItemType = "treasure";
        _hiddenItem.Active = 0;
        _hiddenItem.Interactive = 0;
    }

    void OnControlBreak(){
        _hiddenItem.Active = 1;
        _hiddenItem.Interactive = 1;
    }
}

// 创建一个有容器的宝藏
AsSceneTreasure@ BuildTreasureBox(
    string containerName, 
    string itemName, 
    Vector3 containerPosition,
    Vector3 itemPosition,
    float containerYawAngle, 
    float itemYawAngle, 
    int hp, 
    string hitEffect, 
    string breakEffect
    ){
    AsSceneTreasure treasure(containerName, itemName);
    treasure.ContainerPosition = containerPosition;
    treasure.ItemPosition = itemPosition;
    treasure.ContainerYawAngle = containerYawAngle;
    treasure.ItemYawAngle = itemYawAngle;
    treasure.Control.DefaultPose = 0;
    treasure.Control.BreakPose = 1;
    treasure.Control.HitEffect = hitEffect;
    treasure.Control.BreakEffect = breakEffect;
    treasure.Control.HP = hp;
    return treasure;
}


AsSceneTreasure@ BuildTreasureBox(
    string containerName, 
    string itemName, 
    int containerWaypoint,
    int itemWaypoint,
    float containerYawAngle, 
    float itemYawAngle, 
    int hp, 
    string hitEffect, 
    string breakEffect
    ){
    Vector3 waypointOffset = Vector3(0,0, 30);
    int targetIndex = 0;
    SetTarget(targetIndex, "waypoint", containerWaypoint);
    Vector3 containerPosition = GetPosition(targetIndex) - waypointOffset;
    SetTarget(targetIndex, "waypoint", itemWaypoint);
    Vector3 itemPosition = GetPosition(targetIndex) - waypointOffset;
    itemPosition += Vector3(0,0,5);
    AsSceneTreasure@ treasure = BuildTreasureBox(containerName, itemName, containerPosition, itemPosition, containerYawAngle, itemYawAngle, hp, hitEffect, breakEffect);
    return treasure;
}

bool CreateTreasureFromCsv(string filename){
    File file(filename);
    if (!file.open){
        Print("无法打开", filename);
        return false;
    }
    file.ReadLine(); // ignore
    while(!file.eof){
        string line = file.ReadLine().Trimmed();
        string[] cells = line.Split(',', true);
        uint atleastCount = 10; // 至少10个单元格
        if (cells.GetSize() < atleastCount){
            Print(cells.GetSize());
            continue;
        }
        for (uint i = 0; i < cells.GetSize(); i++){
            int lineNumber = i + 2;
            cells[i] = cells[i].Trimmed();
        }
        string containerName = cells[1];
        string[] itemNameList = cells[2].Split('|');
        int containerWaypoint = cells[3].ToInt();
        int itemWaypoint = cells[4].ToInt();
        float containerYawAngle = cells[5].ToFloat();
        float itemYawAngle = cells[6].ToFloat();
        int hp = cells[7].ToInt();
        string hitEffect = cells[8];
        string breakEffect = cells[9];

        for (uint j = 0; j < itemNameList.GetSize(); j++){
            itemNameList[j] = itemNameList[j].Trimmed();
        }

        string itemName = itemNameList[Rand(itemNameList.GetSize())];
        BuildTreasureBox(containerName, itemName, containerWaypoint, itemWaypoint, containerYawAngle, itemYawAngle, hp, hitEffect, breakEffect);
    }
    file.Close();
    return true;
}