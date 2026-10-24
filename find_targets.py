import json

with open(r'D:\MeteorRE\symbols\strings.json', 'r', encoding='utf-8') as f:
    strs = json.load(f)

targets = [
    'HITATTACK', 'ATTACK', 'damage', 'damagevalue',
    'DROPWEAPON', 'SWITCHWEAPON', 'Load Pose Fail',
    'PlayerHP', 'BeginPose', 'moveto', 'defensepose', 'targetpose'
]

for s in strs:
    v = s.get('value', '')
    for t in targets:
        if t.lower() in v.lower():
            print(f"{s['address']}: {v}")
