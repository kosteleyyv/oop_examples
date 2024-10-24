#include "RemovingDoubleWhitespace.h"

 string RemovingDoubleWhitespace::getEditionResult() const {
	string copy = text; // копируем значение поля базового класса
	replace(copy, "  ", " "); // испольуем метод базового класса  для замены двух пробелов на один
	return copy;
}
