#include "AsSceneItem.as"
#include "AsDelegate.as"


// 场景破坏控制
class AsSceneBreakControl{
    AsSceneItem@ BreakableItem;
    int DefaultPose = 0;
    int BreakPose = 1;
    string HitEffect;
    string BreakEffect;
    int HP = 50;

    private bool _alive = true;
    void Bind(){
        if (@BreakableItem != null){
            BreakableItem.ItemType = "machine";
            BreakableItem.Collision = 1;
            BreakableItem.Pose = DefaultPose;
            BreakableItem.AddHandlerOnAttack(FuncDef_AsSceneItemOnAttack(ContainerOnAttack));
            BreakableItem.AddHandlerOnIdle(FuncDef_AsSceneItemOnIdle(ContainerOnIdle));
        }
        if (@OnInit != null){
            OnInit();
        }
    }

    FuncDefAction@ OnInit;

    FuncDefAction@ OnBreak;


    private void ContainerOnAttack(AsSceneItem@ item, int charId, int damage) {
        HP -= damage;
        if ( HP>0 )
        {
            NetEvent(1);
            Output("effect:", BreakableItem.Id, HitEffect);
            BreakableItem.CreateEffect(HitEffect);
            NetEvent(0);
            return;
        }
        
        if ( BreakableItem.Pose == BreakPose )
        {
            return;
        }
        
        NetEvent(1);
        BreakableItem.CreateEffect(BreakEffect);
        BreakableItem.Pose = BreakPose;
        BreakableItem.Interactive = 0;
        BreakableItem.Collision = 0;
        
        if (@OnBreak != null){
            OnBreak();
        }

        NetEvent(0);
        
        return;
    }
    
    private void ContainerOnIdle(AsSceneItem@ item){
        if ( _alive )
        {
            if ( RemoveContainer() )
            {
                _alive = false;
            }
        }
    }

    private bool RemoveContainer(){
        int state;
        int pose;
        
        pose = BreakableItem.Pose;
        if ( pose==0 )
        {
            return false;
        }
        
        state = BreakableItem.State;
        if ( state!=3 )
        {
            return false;
        }
        
        NetEvent(1);
        BreakableItem.Active = 0;
        NetEvent(0);
        Output("remove item", BreakableItem.Id);
        return true;
    }
}
