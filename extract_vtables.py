import struct, json

with open(r'D:\MeteorRE\Meteor.exe', 'rb') as f:
    f.seek(0x1a8000) # .rdata offset
    rdata = f.read(0x1c000)

rdata_base = 0x005a8000
vtables = []

i = 0
while i < len(rdata) - 12:
    fn_ptrs = []
    curr = i
    while curr <= len(rdata) - 4:
        ptr = struct.unpack('<I', rdata[curr:curr+4])[0]
        if 0x00401000 <= ptr <= 0x005a8000:
            fn_ptrs.append(hex(ptr))
            curr += 4
        else:
            break
    if len(fn_ptrs) >= 3:
        vtable_va = rdata_base + i
        vtables.append({
            'address': hex(vtable_va),
            'method_count': len(fn_ptrs),
            'methods': fn_ptrs
        })
        i = curr
    else:
        i += 4

print(f'Detected {len(vtables)} vtables.')
sorted_vt = sorted(vtables, key=lambda x: x['method_count'], reverse=True)
for v in sorted_vt[:10]:
    addr = v['address']
    count = v['method_count']
    print(f'  {addr}: {count} methods')

with open(r'D:\MeteorRE\symbols\vtables.json', 'w', encoding='utf-8') as f:
    json.dump(vtables, f, indent=2)
print("Saved to D:\\MeteorRE\\symbols\\vtables.json")
