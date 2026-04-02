# Project2
Структуры и объединения. Сортировка массива структур. Работа с файлами.

Вариант 8. Задание 1.

Определить структурный тип, описывающий компьютерные игры (название игры,
студия разработчик, стоимость подписки, объем аудитории игроков,
поддерживаемые платформы: PC, mobile, gamepad; тип: RPG, стратегия, гонки,
авиасимулятор и др.). Заполнить структурный массив 20-ю записями. Переписать из
исходного массива в другой массив, информацию только о шутерах от id Software.
Затем новый массив отсортировать по объему аудитории. Вывести все данные по
конкретной игре. Вывести 4 самых недорогих игр. Реализовать функцию изменения
игры. В отдельный массив поместить все мобильные игры, в которых можно
погонять. Реализовать вывод отфильтрованных данных в виде оберточной функции.

Требования к решению:
1. Использовать функции для каждой подзадачи.
2. Как минимум одно поле должно иметь перечисляемый тип данных
(enum).
3. При описании структуры использовать в качестве одного из полей
структуру.
4. Ввод данных осуществить в виде инициализации массива структур
внутри программы (не с клавиатуры).
5. Алгоритм сортировки – пузырьком.
6. После выполнения следующего занятия выложить решение на github.

Результат выполнения кода:
    
     =================== ALL GAMES ===================
    
     Name                    Developer       Price      Players      Platforms               Genre
     ---------------------------------------------------------------------------------------------------------
     DOOM Eternal            id Software     $9.99      5 mil.       PC:1 Mob:0 Pad:0        Shooter
     DOOM 2016               id Software     $7.99      4 mil.       PC:1 Mob:0 Pad:0        Shooter
     Quake Champions         id Software     $0.00      1 mil.       PC:1 Mob:0 Pad:0        Shooter
     CS:GO                   Valve           $0.99      25 mil.      PC:1 Mob:0 Pad:0        Shooter
     PUBG Mobile             Tencent         $0.00      100 mil.     PC:0 Mob:1 Pad:0        Shooter
     Call of Duty Mobile     Activision      $0.99      80 mil.      PC:0 Mob:1 Pad:0        Shooter
     Half-Life 2             Valve           $2.99      12 mil.      PC:1 Mob:0 Pad:0        Shooter
     Wolfenstein             MachineGames    $8.99      3 mil.       PC:1 Mob:0 Pad:0        Shooter
     Asphalt 9               Gameloft        $0.99      50 mil.      PC:0 Mob:1 Pad:0        Racing
     Need for Speed          EA              $11.99     8 mil.       PC:1 Mob:0 Pad:1        Racing
     Forza Horizon 5         Playground      $12.99     15 mil.      PC:1 Mob:1 Pad:1        Racing
     Cyberpunk 2077          CD Projekt      $14.99     25 mil.      PC:1 Mob:0 Pad:0        RPG
     The Witcher 3           CD Projekt      $9.99      20 mil.      PC:1 Mob:0 Pad:0        RPG
     Genshin Impact          miHoYo          $0.00      60 mil.      PC:1 Mob:1 Pad:0        RPG
     StarCraft II            Blizzard        $0.00      6 mil.       PC:1 Mob:0 Pad:0        Strategy
     Warcraft III            Blizzard        $7.99      4 mil.       PC:1 Mob:0 Pad:0        Strategy
     Microsoft Flight Sim    Asobo           $15.99     5 mil.       PC:1 Mob:0 Pad:0        Flight simulator
     IL-2 Sturmovik          1C              $19.99     1 mil.       PC:1 Mob:0 Pad:0        Flight simulator
     Minecraft               Mojang          $7.99      140 mil.     PC:1 Mob:1 Pad:0        Adventure
     Portal 2                Valve           $3.99      8 mil.       PC:1 Mob:0 Pad:0        Action
    
     =================== ID SOFTWARE SHOOTERS ===================
    
     Name                    Developer       Price      Players      Platforms               Genre
     ---------------------------------------------------------------------------------------------------------
     DOOM Eternal            id Software     $9.99      5 mil.       PC:1 Mob:0 Pad:0        Shooter
     DOOM 2016               id Software     $7.99      4 mil.       PC:1 Mob:0 Pad:0        Shooter
     Quake Champions         id Software     $0.00      1 mil.       PC:1 Mob:0 Pad:0        Shooter
    
     =================== SORTED BY PLAYERS (descending) ===================
    
     Name                    Developer       Price      Players      Platforms               Genre
     ---------------------------------------------------------------------------------------------------------
     DOOM Eternal            id Software     $9.99      5 mil.       PC:1 Mob:0 Pad:0        Shooter
     DOOM 2016               id Software     $7.99      4 mil.       PC:1 Mob:0 Pad:0        Shooter
     Quake Champions         id Software     $0.00      1 mil.       PC:1 Mob:0 Pad:0        Shooter
    
     =================== FOUND: Genshin Impact ===================
    
     Name                    Developer       Price      Players      Platforms               Genre
     ---------------------------------------------------------------------------------------------------------
     Genshin Impact          miHoYo          $0.00      60 mil.      PC:1 Mob:1 Pad:0        RPG
    
     Game "Football" not found!
    
     =================== 4 CHEAPEST GAMES ===================
    
     1. Quake Champions: Price = $0.00
     2. PUBG Mobile: Price = $0.00
     3. Genshin Impact: Price = $0.00
     4. StarCraft II: Price = $0.00
    
     Game modified successfully!
    
     =================== FOUND: Need for Speed 2 ===================
    
     Name                    Developer       Price      Players      Platforms               Genre
     ---------------------------------------------------------------------------------------------------------
     Need for Speed 2        EA              $12.89     9 mil.       PC:1 Mob:0 Pad:1        Racing
    
     =================== FILTERED: MOBILE RACING GAMES (2 games) ===================
    
     Name                    Developer       Price      Players      Platforms               Genre
     ---------------------------------------------------------------------------------------------------------
     Asphalt 9               Gameloft        $0.99      50 mil.      PC:0 Mob:1 Pad:0        Racing
     Forza Horizon 5         Playground      $12.99     15 mil.      PC:1 Mob:1 Pad:1        Racing
