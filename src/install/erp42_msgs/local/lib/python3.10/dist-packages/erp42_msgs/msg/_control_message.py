# generated from rosidl_generator_py/resource/_idl.py.em
# with input from erp42_msgs:msg/ControlMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ControlMessage(type):
    """Metaclass of message 'ControlMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('erp42_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'erp42_msgs.msg.ControlMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__control_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__control_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__control_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__control_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__control_message

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ControlMessage(metaclass=Metaclass_ControlMessage):
    """Message class 'ControlMessage'."""

    __slots__ = [
        '_mora',
        '_estop',
        '_gear',
        '_speed',
        '_steer',
        '_brake',
        '_alive',
    ]

    _fields_and_field_types = {
        'mora': 'uint8',
        'estop': 'uint8',
        'gear': 'uint8',
        'speed': 'uint16',
        'steer': 'int16',
        'brake': 'uint8',
        'alive': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mora = kwargs.get('mora', int())
        self.estop = kwargs.get('estop', int())
        self.gear = kwargs.get('gear', int())
        self.speed = kwargs.get('speed', int())
        self.steer = kwargs.get('steer', int())
        self.brake = kwargs.get('brake', int())
        self.alive = kwargs.get('alive', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.mora != other.mora:
            return False
        if self.estop != other.estop:
            return False
        if self.gear != other.gear:
            return False
        if self.speed != other.speed:
            return False
        if self.steer != other.steer:
            return False
        if self.brake != other.brake:
            return False
        if self.alive != other.alive:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mora(self):
        """Message field 'mora'."""
        return self._mora

    @mora.setter
    def mora(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mora' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'mora' field must be an unsigned integer in [0, 255]"
        self._mora = value

    @builtins.property
    def estop(self):
        """Message field 'estop'."""
        return self._estop

    @estop.setter
    def estop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'estop' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'estop' field must be an unsigned integer in [0, 255]"
        self._estop = value

    @builtins.property
    def gear(self):
        """Message field 'gear'."""
        return self._gear

    @gear.setter
    def gear(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gear' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gear' field must be an unsigned integer in [0, 255]"
        self._gear = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'speed' field must be an unsigned integer in [0, 65535]"
        self._speed = value

    @builtins.property
    def steer(self):
        """Message field 'steer'."""
        return self._steer

    @steer.setter
    def steer(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'steer' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'steer' field must be an integer in [-32768, 32767]"
        self._steer = value

    @builtins.property
    def brake(self):
        """Message field 'brake'."""
        return self._brake

    @brake.setter
    def brake(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'brake' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'brake' field must be an unsigned integer in [0, 255]"
        self._brake = value

    @builtins.property
    def alive(self):
        """Message field 'alive'."""
        return self._alive

    @alive.setter
    def alive(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'alive' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'alive' field must be an unsigned integer in [0, 255]"
        self._alive = value
