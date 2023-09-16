#!/usr/bin/python3

ls = ['id', 'created_at', 'updated_at', 'name', 'state_id']

maxlen = max(len(item) for item in ls)

for item in ls:
    print(f"{item:>{maxlen}}:")
