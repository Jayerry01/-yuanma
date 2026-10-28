uint FUN_00421b00(void)

{
  byte in_ID;
  
  return (uint)((in_ID & 1) != 1) * 0x200000 ^ (uint)(in_ID & 1) * 0x200000;
}



// WARNING: Removing unreachable block (ram,0x00421b3f)
