#include <iostream>
#include <cmath>
using namespace std;
class direct_mapping

{
    int word_size;
    int cache_block_size;
    int ram_size;
    int ram_arr_size;
    int search;
    int cache_arr[];

public:
    void data_input()
    {
        cout << endl
             << endl
             << "****Enter the size of the cache in KB : ";
        cin >> cache_block_size;
        cache_block_size = (log(cache_block_size) / log(2)) + 10;
        cout << endl
             << "****Enter the size of main memory in MB : ";
        cin >> ram_size;
        ram_size = (log(ram_size) / log(2)) + 20;
        cout << endl
             << "****Enter the word size Bytes : ";
        cin >> word_size;

        word_size = (log(word_size) / log(2));
        // ram_arr_size=pow(2,(ram_size)/1000);
        ram_arr_size = 100000; 
        // ram_arr_size=ram_size;
        cache_block_size = (cache_block_size - word_size);
    }
    void display_cache()
    {
        int i;
        cout << endl
             << endl
             << "               *****";
        cout << "\n     "
             << "Tag bit"
             << "   "
             << "r"
             << "     "
             << "wordsize";
        for (i = 0; i < cache_block_size; i++)
        {
            cout << endl;
            cout << "        " << (cache_arr[i]) - i << "       " << i << "       " << word_size;
        }
        // cout << "*****";
        cout << endl
             << "               *****" << endl
             << endl;
    }
    void cache_values(int ram_arr[])     // one time display and ram init
    {
        int i;
        int k = 0;
        for (i = 0; i < cache_block_size; i++)
        {
            cache_arr[i] = i;
            cout << cache_arr[i] << "  ";
        }
        for (i = 0; i < (ram_arr_size); i++)
        {
            ram_arr[i] = k;
            k++;
        }
    }
    void load_from_ram(int ram_arr[])
    {
        cout << endl
             << "\nLoading the ram blocks to the cache lines";
        int mod_fnc = (search % cache_block_size);
        cache_arr[mod_fnc] = ram_arr[search];
        display_cache();
    }

    void fetch(int ram_arr[])
    {
        cout << "\n Enter the block no. to fetch the data.";
        // int search;
        cin >> search;
        int mod_fnc;
        mod_fnc = (search % cache_block_size);
        if (search == cache_arr[mod_fnc])
        {
            cout << endl
                 << endl
                 << "\n           ****cache hit!!!****" << endl
                 << "\n The data of block " << search << " has been found in line no. " << mod_fnc << " of cache";
            display_cache();
        }
        else
        {
            cout << endl
                 << endl
                 << "\n           ****cache miss:(****" << endl
                 << "\n The data of block " << search << " not found in cache but present in ram.\n \n           Direct mapping to line no. " << mod_fnc << " of cache";
            load_from_ram(ram_arr);
        }
    }
};
int main()
{

    cout << endl
         << endl
         << "		 ____  ___ ___   ____  ____ _____       		___  ___  ___        ____ " << endl
         << "		|    |  |  |  \\ |     |       |		|\\  /|    /\\   |   ||   |  |  |\\   ||     " << endl
         << "		|    |  |  |__| |___  |       |		| \\/ |   /__\\  |___||___|  |  | \\  ||  __ " << endl
         << "		|    |  |  |\\   |     |       |		|    |  /    \\ |    | 	   |  |  \\ ||    |" << endl
         << "		|____| _|_ | \\  |____ |____   |		|    | /      \\|    |	  _|_ |   \\||____|";
    cout << endl
         << endl
         << endl
         << endl;
    int ram_size;
    direct_mapping active;
    active.data_input();

    int ram_arr[1000000];
    active.cache_values(ram_arr);
    cout << endl
         << endl
         << endl
         << "                        ****The Simulator is ready to use****" << endl
         << endl;
    int toggle2 = 1;
    while (toggle2 != 3)
    {
        if (toggle2 == 2)
        {
            active.data_input();
        }
        active.fetch(ram_arr);
        cout << "\nPress 1 to continue , 2 to reinsert the data and  3 to leave : ";
        cin >> toggle2;
    }
    return 0;
}