#!/usr/bin/python3
""" Place Module for HBNB project """
from models.base_model import BaseModel
from models.base_model import Base
import models
from sqlalchemy import Column, String, ForeignKey, Integer, Float


class Place(BaseModel, Base):
    """ A place to stay """
    if models.storage_type == 'db':
        __tablename__ = 'places'

        city_id = Column(String(length=60), ForeignKey('cities.id'),
                         nullable=False)
        user_id = Column(String(length=60), ForeignKey('users.id'),
                         nullable=False)
        name = Column(String(length=128), nullable=False)
        description = Column(String(length=1024), nullable=False)
        number_rooms = Column(Integer, default=0, nullable=False)
        number_bathrooms = Column(Integer, default=0, nullable=False)
        max_guest = Column(Integer, default=0, nullable=False)
        price_by_night = Column(Integer, default=0, nullable=False)
        latitude = Column(Float, nullable=False)
        longitude = Column(Float, nullable=False)
    else:
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
