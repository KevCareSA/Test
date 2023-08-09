#!/usr/bin/python3
from models import storage
from models.base_model import BaseModel
from models.user import User
from models.state import State
from models.city import City
from models.place import Place
from models.amenity import Amenity
from models.review import Review


all_objs = storage.all()
print("-- Reloaded objects --")
for obj_id in all_objs.keys():
    obj = all_objs[obj_id]
    print(obj)

print("-- Create a new User --")
my_user = Place()
my_user.city_id = "767c2a50-4aef-410a-bad8-360734991b8b"
my_user.name = "49 Fox Glove"
my_user.latitude = 4.4
my_user.number_rooms = 4
my_user.amenity_ids = ["shfioefwe-asfdhaoef", "laskdfs-alskfjle-aslfkjel"]
my_user.save()
print(my_user)

print("-- Create a new User 2 --")
my_user2 = Place()
my_user2.city_id = "767c2a50-4aef-410a-bad8-360734991b8b"
my_user2.name = "73 Hills Drive"
my_user2.latitude = 33.3
my_user2.number_rooms = 2
my_user.amenity_ids = ["he-asdkfaoef-slkdjfskdjf", "laskdfs-alskfjle-aslfkjel"]
my_user2.save()
print(my_user2)
