import uuid

id1 = uuid.uuid4()
id2 = uuid.uuid4()

sid1 = str(id1)
print("sid1:", sid1)

newid1 = uuid.UUID(sid1)


print("id1:", id1)
print("id2:", id2)
print(id1 == id2)

print(id1 == newid1)
