#!/usr/bin/env python3
import os
import sys
import subprocess
import yaml

DATASET_DIR = os.getenv("DATASET_DIR", "/app/dataset")

def convert_bag(bag_name):
    bag_path = os.path.join(DATASET_DIR, bag_name)
    if not os.path.isdir(bag_path):
        print(f"[-] {bag_path} is not a directory, skipping.")
        return False

    out_name = f"{bag_name}_mcap"
    out_path = os.path.join(DATASET_DIR, out_name)

    if os.path.exists(out_path):
        print(f"[!] '{out_name}' already exists. Skipping.")
        return True

    # Check if there is a .db3 file inside
    db3_files = [f for f in os.listdir(bag_path) if f.endswith(".db3")]
    if not db3_files:
        print(f"[-] No .db3 found in {bag_name}, skipping.")
        return False

    config = {
        "output_bags": [
            {
                "uri": out_path,
                "storage_id": "mcap",
                "all": True,
            }
        ]
    }

    config_path = f"/tmp/convert_{bag_name}.yaml"
    with open(config_path, "w") as f:
        yaml.dump(config, f)

    print(f"\n[*] Starting conversion: {bag_name} -> {out_name}...")
    cmd = ["ros2", "bag", "convert", "-i", bag_path, "-o", config_path]
    res = subprocess.run(cmd)

    if os.path.exists(config_path):
        os.remove(config_path)

    if res.returncode == 0:
        print(f"[+] Successfully converted {bag_name} to {out_name}!\n")
        return True
    else:
        print(f"[x] Failed to convert {bag_name} (exit code: {res.returncode})\n")
        return False

def main():
    if len(sys.argv) > 1:
        targets = sys.argv[1:]
    else:
        # Find all bags with .db3
        targets = []
        for item in sorted(os.listdir(DATASET_DIR)):
            item_path = os.path.join(DATASET_DIR, item)
            if os.path.isdir(item_path) and not item.endswith("_mcap"):
                if any(f.endswith(".db3") for f in os.listdir(item_path)):
                    targets.append(item)

    if not targets:
        print(f"No .db3 bags found to convert in {DATASET_DIR}")
        return

    print(f"Target bags to convert: {targets}")
    for target in targets:
        convert_bag(target)

if __name__ == "__main__":
    main()

