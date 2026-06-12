import std;
import collections;
import interface;

void stack_test()
{
	std::println("Stack Example");

	Stack<int> stack;
	stack.Push(10);
	stack.Push(1);
	stack.Push(20);

	auto it = stack.GetEnumerator();
	while (it->MoveNext())
	{
		std::println("{}", it->Current());
	}

	std::println("Pop {}", stack.Pop());
	std::println("Peek {}", stack.Peek());
	std::println("Count {}", stack.Count());
	std::println("-------------------------\n");

	return;
}

void queue_test() {
	std::println("Queue Example");

	Queue<int> queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);

	auto it = queue.GetEnumerator();

	while (it->MoveNext()) {
		std::println("{}", it->Current());
	}

	std::println("Dequeue: {}", queue.Dequeue());
	std::println("Peek: {}", queue.Peek());
	std::println("Count: {}", queue.Count());
}

void hashset_test() {
	HashSet<std::string> names;

	names.Add("Fedor");
	names.Add("Masha");
	names.Add("Dima");
	names.Add("Sergey");

	std::println("Чиcло имнен: {}", names.Count());
	std::println("Проверка метода Contains с помощью \"Fedor\"{}", names.Contains("Fedor"));
	if (names.Remove("Fedor")) {

		std::println("Им Fedor удалено");
	}

	names.SetCapacity(100);
	std::println("Текущая ёмкость коллекции: {}", names.Capacity());


	auto it = names.GetEnumerator();
	while (it->MoveNext())
	{
		std::println("{}", it->Current());
	}
	names.Clear();
}

void list_test()
{
	List<int> list;
	list.Add(10);
	list.Add(20);
	list.Add(30);
	list.Add(40);

	list.Insert(0, 50);
	list.RemoveAt(4);
	std::println("размер: {}", list.Count());
	std::println("ёмкость: {}", list.Capacity());
	list.SetCapacity(25);
	std::println("ёмкость: {}", list.Capacity());
	if (list.Contains(20)) 
	{
		std::println("20 есть");
	}
	list[0] = 66;
	std::println("1 элемент: {}", list[0]);
	list.Remove(40);
	auto it = list.GetEnumerator();
	while (it->MoveNext())
	{
		std::println("{}", it->Current());
	}
	list.Clear();
	std::println("после очистики: {}", list.Count());

}

void dictionary_test() {

	Dictionary<std::string, int> d;

	d.Add({ "key1",1 });
	d.Add({ "key2",2 });
	d.Add({ "key3",3 });

	std::println("Элементов в словаре: {}", d.Count());

	d["key1"] = 10;

	if (d.Contains({ "key1", 10 }))
		std::println("Содержит элемент (\"key1\", {})", d["key1"]);

	if (d.Remove({ "key2",2 }))
		std::println("Удалён элемент (\"key2\", 2)");

	const std::size_t test_capacity = 10;

	d.SetCapacity(test_capacity);

	std::println("Предполагаемая ёмкость: {}, установленна ёскость: {}", test_capacity, d.Capacity());

	auto it = d.GetEnumerator();
	while (it->MoveNext())
	{
		std::println("({}, {})", it->Current().first, it->Current().second);
	}

	d.Clear();

	std::println("Размер после очистки: {}", d.Count());
}



int main() {
	stack_test();
	queue_test();
	hashset_test();
	list_test();
	dictionary_test();

	return 0;
};