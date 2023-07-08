# generated from rosidl_generator_py/resource/_idl.py.em
# with input from bridge_interface:msg/Server2Robot.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Server2Robot(type):
    """Metaclass of message 'Server2Robot'."""

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
            module = import_type_support('bridge_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'bridge_interface.msg.Server2Robot')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__server2_robot
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__server2_robot
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__server2_robot
            cls._TYPE_SUPPORT = module.type_support_msg__msg__server2_robot
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__server2_robot

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Server2Robot(metaclass=Metaclass_Server2Robot):
    """Message class 'Server2Robot'."""

    __slots__ = [
        '_gate',
        '_activate',
        '_engage',
        '_estop',
    ]

    _fields_and_field_types = {
        'gate': 'string',
        'activate': 'boolean',
        'engage': 'boolean',
        'estop': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.gate = kwargs.get('gate', str())
        self.activate = kwargs.get('activate', bool())
        self.engage = kwargs.get('engage', bool())
        self.estop = kwargs.get('estop', bool())

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
        if self.gate != other.gate:
            return False
        if self.activate != other.activate:
            return False
        if self.engage != other.engage:
            return False
        if self.estop != other.estop:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def gate(self):
        """Message field 'gate'."""
        return self._gate

    @gate.setter
    def gate(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'gate' field must be of type 'str'"
        self._gate = value

    @builtins.property
    def activate(self):
        """Message field 'activate'."""
        return self._activate

    @activate.setter
    def activate(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'activate' field must be of type 'bool'"
        self._activate = value

    @builtins.property
    def engage(self):
        """Message field 'engage'."""
        return self._engage

    @engage.setter
    def engage(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'engage' field must be of type 'bool'"
        self._engage = value

    @builtins.property
    def estop(self):
        """Message field 'estop'."""
        return self._estop

    @estop.setter
    def estop(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'estop' field must be of type 'bool'"
        self._estop = value
