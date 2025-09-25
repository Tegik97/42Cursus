#include "Serializer.hpp"
#include "data.hpp"
#include <iostream>

int	main(void)
{
	Data	data;

	std::cout << "Original data address: " << &data << std::endl;

	uintptr_t	serializedData = Serializer::serialize(&data);
	std::cout << "Serialized value: " << serializedData << std::endl;

	Data*	deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized address: " << deserializedData << std::endl;

	if (&data == deserializedData)
		std::cout << "\n✅ SUCCESS: Pointers match!" << std::endl;
	else
		std::cout << "\n❌ FAIL: Pointers don't match!" << std::endl;
}