#!/usr/bin/python3

"""
This module constains the Place class which inherits Basemodel

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 09/08/2023
"""


from models.base_model import BaseModel


class Place(BaseModel):
    """This class contains information on Place instances

    Attributes <PUBLIC>:
        city_id(str): contains <City obj>.id
        user_id(str): contains <User obj>.id
        name(str): name of Place instance
        description(str): description of Place instance
        number_rooms(int): number of rooms
        number_bathrooms(int): number of bathrooms
        max_guest(int): maximum number of guests a Place instance can occupy
        price_by_night(int): price to stay the night
        latitude(float): latitudinal positon of Place's location
        longitude(float): longitudinal positon of Place's location
        amenity_ids(list:str): list of amenity id's
    """
    city_id = ""
    user_id = ""
    name = ""
    description = ""
    number_rooms = 0
    number_bathrooms = 0
    max_guest = 0
    price_by_night = 0
    latitude = 0.0
    longitude = 0.0
    amenity_ids = []
