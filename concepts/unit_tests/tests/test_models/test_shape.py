import unittest
from models.shape import Shape


class Test_Shape(unittest.TestCase):

    def test_area(self):
        sh1 = Shape(2, 4)
        self.assertEqual(sh1.area(), 8)
        self.assertNotEqual(sh1.area(), -5)

    def test_obj_string(self):
        sh1 = Shape(2, 4)
        self.assertEqual(str(sh1), "width: 2 | height: 4")

    def test_exceptions(self):
        with self.assertRaises(TypeError):
            Shape("hey", 4)


if __name__ == '__main__':
    unittest.main()
