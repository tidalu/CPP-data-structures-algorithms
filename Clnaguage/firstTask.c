#include <stdio.h>
#include <stdlib.h>

struct TennisPlayer
{
    char first_name[50];
    char last_name[50];
    int age;
    int price_money;
};

double avg_price(struct TennisPlayer array[], int size);

int main()
{
    printf("Enter the number of players: ");
    int num_players;
    scanf("%d", &num_players);
    if (num_players < 0)
    {
        return 1;
    }
    struct TennisPlayer *Player = malloc(num_players * sizeof(struct TennisPlayer));

    for (int i = 0; i < num_players; i++)
    {
        printf("Enter %dst player's name: ", i + 1);
        scanf("%s %[^\n]", Player[i].first_name, Player[i].last_name);
        printf("Enter %dst player's age: ", i + 1);
        scanf("%d", &Player[i].age);
        printf("Enter %dst player's prize: ", i + 1);
        scanf("%d", &Player[i].price_money);
        printf("---------------------------------\n");
    }

    printf("=========================================\n");

    for (int i = 0; i < num_players; i++)
    {
        printf("---------------------------------\n");
        printf("Informations of the %dst User: \n", i + 1);

        printf("Users name: %s %s\n", Player[i].first_name, Player[i].last_name);
        printf("User's age: %d  \n", Player[i].age);
        printf("User's price_money: %d  \n", Player[i].price_money);
        printf("---------------------------------\n");
    }

    printf("Average of the user's price money: %lf\n", avg_price(Player, num_players));
    free(Player);
    return 0;
}

double avg_price(struct TennisPlayer array[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i].price_money;
    }
    double average = sum / size;
    return average;
}