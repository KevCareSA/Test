#!/usr/bin/python3
""" Place Module for HBNB project """
from models.base_model import BaseModel
from models.base_model import Base
import models
from models.amenity import Amenity
from models.review import Review
from sqlalchemy import Column, String, ForeignKey, Integer, Float, Table
from sqlalchemy.orm import relationship

if models.storage_type == 'db':
    association_table = Table(
        'place_amenity', Base.metadata,
        Column('place_id', String(length=60), ForeignKey('places.id'),
               primary_key=True, nullable=False),
        Column('amenity_id', String(length=60), ForeignKey('amenities.id'),
               primary_key=True, nullable=False)
        )


class Place(BaseModel, Base):
    """ A place to stay """
    if models.storage_type == 'db':
        __tablename__ = 'places'

        city_id = Column(String(length=60), ForeignKey('cities.id'),
                         nullable=False)
        user_id = Column(String(length=60), ForeignKey('users.id'),
                         nullable=False)
        name = Column(String(length=128), nullable=False)
        description = Column(String(length=1024), nullable=True)
        number_rooms = Column(Integer, default=0, nullable=False)
        number_bathrooms = Column(Integer, default=0, nullable=False)
        max_guest = Column(Integer, default=0, nullable=False)
        price_by_night = Column(Integer, default=0, nullable=False)
        latitude = Column(Float, nullable=True)
        longitude = Column(Float, nullable=True)
        reviews = relationship("Review", backref="place",
                               cascade="all, delete-orphan")
        amenities = relationship("Amenity", secondary="place_amenity",
                                 viewonly=False)
        amenity_ids = []
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

        @property
        def reviews(self):
            """getter attribute reviews that returns the list of Review ...
            instances with place_id equals to the current Place.id
            """
            rev_list = []
            for obj in models.storage.all(Review).values():
                if obj.place_id == self.id:
                    rev_list.append(obj)
            return rev_list

        @property
        def amenities(self):
            """eturns the list of Amenity instances based on the attribute
            amenity_ids that contains all Amenity.id linked to the Place
            """
            amenity_list = []
            for obj in models.storage.all(Amenity).values():
                if obj.id in self.amenity_ids:
                    amenity_list.append(obj)
            return amenity_list

        @amenities.setter
        def amenities(self, obj):
            if type(obj) == Amenity:
                self.amenity_ids.append(obj.id)
