# natrix_interpreter
## Что это?
Интерпретатор байткода для языка, похожего на питон (отсюда и название (`natrix` с английского -- 'уж')) для микроконтроллеров (Arduino, etc.)  
## Зачем?
Прост  ¯ \ _ (ツ) _ / ¯  
А если серьёзно -- интересный и сложный проект, который может пригодиться хотя-бы 1,5 людям.  
Да и каждый программист в итоге пишет свой язык программирования :)  
## Как это безумие работать будет?
Интерпретатор байткода на C/Wire  
Генератор байткода на Python  
В данном случае микроконтроллер -- сервер; ему отправляется байткод, он его исполняет.
## Что готово на данный момент?
Полурабочий непротестированный неоптимизированный прототип исполнителя, реализованы не все команды.
 * Глобальная область видимости (и только она)
 * Объекты (целые числа, дробные, символ, строка)
 * Поля у объекта
## Как потрогать?
Собрать CMake, запустить.
