#!/usr/bin/env python3
"""
act_pos_mapper.py - Reconstructs the Complete Combat State Machine & Pose Mapping
Sources:
  - C:\\Program Files (x86)\\Meteor\\Common\\character.act (Combo Transitions & Groups)
  - C:\\Program Files (x86)\\Meteor\\pmodel\\p0.pos (Animation Frame Windows)
"""

import os
import sys
import re
import json

ACT_PATH = r"C:\Program Files (x86)\Meteor\Common\character.act"
POS_PATH = r"C:\Program Files (x86)\Meteor\pmodel\p0.pos"

def parse_pos(pos_file):
    with open(pos_file, 'r', encoding='gbk', errors='ignore') as f:
        content = f.read()

    poses = {}
    pattern = re.compile(r'Pose\s+(\d+)\s*\{([^}]+)\}', re.MULTILINE)
    for match in pattern.finditer(content):
        pose_id = int(match.group(1))
        body = match.group(2)
        
        info = {"pose_id": pose_id}
        for line in body.splitlines():
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) >= 2:
                key = parts[0].lower()
                try:
                    val = int(parts[1])
                except ValueError:
                    val = parts[1]
                info[key] = val
        poses[pose_id] = info
    return poses

def parse_act(act_file):
    with open(act_file, 'r', encoding='gbk', errors='ignore') as f:
        lines = f.readlines()

    groups = []
    transitions = {}

    group_pat = re.compile(r'group\(([^)]+)\)')
    trans_pat = re.compile(r'^(\d+)\(([^)]+)\)')

    for line in lines:
        line = line.strip()
        if not line:
            continue
        gm = group_pat.search(line)
        if gm:
            groups.append(gm.group(1))
            continue
        tm = trans_pat.match(line)
        if tm:
            src = int(tm.group(1))
            targets = [int(x.strip()) for x in tm.group(2).split(',') if x.strip().isdigit()]
            transitions[src] = targets

    return groups, transitions

def main():
    if not os.path.exists(ACT_PATH) or not os.path.exists(POS_PATH):
        print(f"[-] Missing input files.")
        sys.exit(1)

    print("[*] Parsing p0.pos...")
    poses = parse_pos(POS_PATH)
    print(f"[+] Loaded {len(poses)} Poses from p0.pos")

    print("[*] Parsing character.act...")
    groups, transitions = parse_act(ACT_PATH)
    print(f"[+] Loaded {len(groups)} Action Groups and {len(transitions)} Combat Transition Nodes")

    # Combine into a unified database
    combat_database = {
        "total_poses": len(poses),
        "total_action_groups": len(groups),
        "total_transition_nodes": len(transitions),
        "action_groups": groups,
        "nodes": {}
    }

    for pose_id, pinfo in poses.items():
        node = dict(pinfo)
        node["combos_to"] = transitions.get(pose_id, [])
        combat_database["nodes"][pose_id] = node

    out_dir = r"D:\MeteorRE\extracted_assets"
    os.makedirs(out_dir, exist_ok=True)
    out_json = os.path.join(out_dir, "combat_fsm_database.json")
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump(combat_database, f, indent=2)
    print(f"[+] Complete Combat FSM Database successfully compiled to {out_json}")

if __name__ == "__main__":
    main()
