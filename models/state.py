#!/usr/bin/python3
""" State Module for HBNB project """
from models.base_model import BaseModel
from models.base_model import Base
import models
from models.city import City
from sqlalchemy import Column, String
from sqlalchemy.orm import relationship


class State(BaseModel, Base):
    """ State class """
    if models.storage_type == 'db':
        __tablename__ = "states"
        name = Column(String(length=128), nullable=False)
        # Define the one-to-many relationship with City
        cities = relationship("City", backref="state",
                              cascade="all, delete-orphan")
    else:
        name = ''

    if models.storage_type != 'db':
        @property
        def cities(self):
            """returns list of city instances with state City instances with
            state_id equal current State.id
            """
            local_cities = []
            all_cities = models.storage.all(City)

            for obj in all_cities.values():
                if self.id == obj.state_id:
                    local_cities.append(obj)
            return local_cities
