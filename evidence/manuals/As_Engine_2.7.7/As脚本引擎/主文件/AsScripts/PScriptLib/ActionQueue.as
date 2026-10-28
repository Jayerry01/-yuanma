funcdef void ActionFunc();

class ActionInfo{
    ActionFunc@ Func;
    float Duration;
    int ExecCount;
}

class ActionQueue{
    private ActionInfo[] _queue;
    private float _previousGameTime;

    void Push(ActionFunc@ func, float duration){
        ActionInfo info;
        @info.Func = func;
        info.Duration = duration;
        _queue.Push(info);
    }

    void Wait(float duration){
        ActionInfo info;
        info.Duration = duration;
        _queue.Push(info);
    }

    void Skip(){
        if (_queue.GetSize() == 0){
            _previousGameTime = 0; // 重置
            return;
        }
        _queue.Erase(0);
    }

    void Clear(){
        _queue.Clear();
        _previousGameTime = 0;
    }

    void Update(){
        if (_queue.GetSize() == 0){
            _previousGameTime = 0; // 重置
            return;
        }

        ActionInfo@ firstInfo = _queue[0];
        if (firstInfo.Duration > 0 || firstInfo.ExecCount == 0){
            if (@firstInfo.Func != null){
                firstInfo.Func();
            }
        }
        firstInfo.ExecCount += 1;

        float currentGameTime = GetGameTimeFloat();
        if (_previousGameTime == 0){
            _previousGameTime = currentGameTime;
        }
        float deltaTime = currentGameTime - _previousGameTime;
        _previousGameTime = currentGameTime;
        
        firstInfo.Duration -= deltaTime;

        if (firstInfo.Duration <= 0){
            _queue.Erase(0);
        }
    }
}
