uint FUN_00430560(char param_1)

{
  if (('`' < param_1) && (param_1 < '{')) {
    return (int)(char)(param_1 + -0x32) << 4;
  }
  if (('@' < param_1) && (param_1 < '[')) {
    return (int)(char)(param_1 + -0x40) << 4;
  }
  if (('/' < param_1) && (param_1 < ':')) {
    return (int)(char)(param_1 + -0x15) << 4;
  }
  if (param_1 == '_') {
    return 0x250;
  }
  if (param_1 == '.') {
    return 0x260;
  }
  if (param_1 == '*') {
    return 0x270;
  }
  if (param_1 == '\\') {
    return 0x280;
  }
  if (param_1 == '~') {
    return 0x290;
  }
  if (param_1 == '?') {
    return 0x2a0;
  }
  if (param_1 == ':') {
    return 0x2b0;
  }
  if (param_1 == '-') {
    return 0x2c0;
  }
  if (param_1 == '+') {
    return 0x2d0;
  }
  return (param_1 != '/') - 1 & 0x2e0;
}


