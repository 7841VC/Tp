#include<iostream>
#include"Site.h"

/*
Создать систему запросов «Сайт → Магазины (3 штуки) → Склад». 
Товар, который интересует клиента – путеводители по разным городам и странам, 
которые имеют ряд характеристик: название, издательство, год, число страниц, наличие фотографий, наличие карты, переплет, формат, автор, количество.
Пользователь использует сайт для нахождения интересующего товара, затем запрос отправляется в магазины, затем на склад. Использовать паттерн «Цепочка обязанностей». 
Данные о товаре для сайта, магазинов и склада берутся из внешних входных файлов «site», «shop1», «shop2» , «shop3» и «warehouse» соответственно.
*/
using namespace std;
int main(void)
{
	setlocale(LC_ALL, "rus");
	Site* s = new Site();
	s->createSite();
	s->getSite();
	s->saveSite();
	int ans;
	while (1)
	{
		
			cout << "Выберите операцию: " << endl;
			cout << "|1| - Вывести сайт" << endl;
			cout << "|2| - Получить интересующий путеводитель" << endl;
			cout << "|3| - выйти из меню покупателя" << endl;
			cin >> ans;
			switch (ans)
			{
				case 1:
				{
					s->getSite();
					break;
				}
				case 2:
				{
					cout << "Введите артикль путеводителя: " << endl;
					cin >> ans;
					travelGuide* tmp = s->findGuide(ans);
					cout << "С приобритением путеводителя: " << endl;
					tmp->getGuide();
					break;
				}
				
			}
			if (ans == 3) { break; }
		
	}

	cin.get(); cin.get();
	delete s;
	return 0;
}
