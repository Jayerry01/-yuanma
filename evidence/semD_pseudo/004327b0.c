uint FUN_004327b0(undefined4 param_1,int param_2)

{
  UINT UVar1;
  MMRESULT MVar2;
  int local_170;
  tMIXERCONTROLDETAILS local_16c;
  tagMIXERLINECONTROLSA local_154;
  tagMIXERLINEA local_13c;
  tagMIXERCONTROLA local_94;
  
  UVar1 = mixerGetNumDevs();
  if (UVar1 == 0) {
    return 0xffffffff;
  }
  local_13c.cbStruct = 0xa8;
  if (param_2 == 0) {
    local_13c.dwComponentType = 0x1005;
  }
  else if (param_2 == 1) {
    local_13c.dwComponentType = 0x1008;
  }
  mixerGetLineInfoA((HMIXEROBJ)0x0,&local_13c,3);
  local_154.pamxctrl = &local_94;
  local_154.cbStruct = 0x18;
  local_154.dwLineID = local_13c.dwLineID;
  local_154.u.dwControlID = 0x50030001;
  local_154.cControls = 1;
  local_154.cbmxctrl = 0x94;
  MVar2 = mixerGetLineControlsA((HMIXEROBJ)0x0,&local_154,2);
  if (MVar2 != 0) {
    return 0xfffffffe;
  }
  local_170 = local_94.Bounds.s.lMaximum - local_94.Bounds._0_4_;
  local_170 = __ftol();
  local_170 = local_170 + local_94.Bounds.s.lMinimum;
  local_16c.cbStruct = 0x18;
  local_16c.dwControlID = local_94.dwControlID;
  local_16c.cChannels = 1;
  local_16c.u.hwndOwner = (HWND)0x0;
  local_16c.cbDetails = 4;
  local_16c.paDetails = &local_170;
  MVar2 = mixerSetControlDetails((HMIXEROBJ)0x0,&local_16c,0);
  return -(uint)(MVar2 != 0) & 0xfffffffd;
}


