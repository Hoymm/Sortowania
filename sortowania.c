#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define N_1 6000
#define N_2 13000
#define N_3 60000
#define N_4 10000
#define N_5 130000

void sprawdzTabliceWPrzypadkuOptymistycznym();
void sprawdzTabliceWPrzypadkuPesymistycznym();
void sprawdzTabliceWPrzypadkuLosowym();
void wyswietlCzasOrazInicjalizujTabliceRosnaco(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]);
void wyswietlCzasOrazInicjalizujTabliceMalejaco(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]);
void wyswietlCzasOrazInicjalizujTabliceLosowo(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]);
void wyswietlInformacjeOSortowaniu(int rozmiar, unsigned long iloscOperacji, unsigned int czas);
int ileCyfrMaLiczba(unsigned long liczba);
int getCurrentTimeInMilliseconds();

void inicjalizujTabliceRosnaco(int tab [], int size);
void inicjalizujTabliceMalejaco(int tab [], int size);
void inicjalizujGeneratorLiczbPseudolosowych();
void inicjalizujTabliceLosowo(int tab [], int size);

// wybor
void posortujTabliceIWyswietlWynikiPrzez_Wybor(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]);
void sortujPrzezWybor(int tab [], int size);

// wstawianie
void posortujTabliceIWyswietlWynikiPrzez_Wstawianie(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]);
void sortujPrzezWstawianie(int tab [], int size);

// scalanie
void posortujTabliceIWyswietlWynikiPrzez_Scalanie(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]);
void uruchomSortowaniePrzezScalanieZeZliczaniemCzasuOrazIlosciOperacji(int tab [], int size);
void sortujPrzezScalanie(int tab [], int poczatek, int koniec, unsigned long *operacjePodst);
void scalTablice(int tab[], int poczatek, int srodek, int koniec, unsigned long *operacjePodst);

// szybkie
void posortujTabliceIWyswietlWynikiSortowaniem_Szybkim(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]);
void uruchomSortowanieSzybkieZeZliczaniemCzasuOrazIlosciOperacji(int tab [], int size);
void sortowanieSzybkie(int tab [], int poczatek, int koniec, unsigned long *operacjePodst);
int podzial(int tab[], int poczatek, int koniec, unsigned long *operacjePodst);

void zamien(int *a, int *b);

int main(void){
	sprawdzTabliceWPrzypadkuOptymistycznym();
	sprawdzTabliceWPrzypadkuPesymistycznym();
	sprawdzTabliceWPrzypadkuLosowym();
}

void sprawdzTabliceWPrzypadkuOptymistycznym(){
	int tab1[N_1+1], tab2[N_2+1], tab3[N_3+1], tab4[N_4+1], tab5[N_5+1];
	printf("################################  OPTYMISTYCZNY  ##########################################");
	printf("\n\t\t ****** WYBOR ****** ");
	wyswietlCzasOrazInicjalizujTabliceRosnaco(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiPrzez_Wybor(tab1, tab2, tab3, tab4, tab5);
	
	printf("\n\n\t\t ****** WSTAWIANIE ****** ");
	wyswietlCzasOrazInicjalizujTabliceRosnaco(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiPrzez_Wstawianie(tab1, tab2, tab3, tab4, tab5);

	printf("\n\n\t\t ****** SCALANIE ****** ");
	wyswietlCzasOrazInicjalizujTabliceRosnaco(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiPrzez_Scalanie(tab1, tab2, tab3, tab4, tab5);
	
	printf("\n\n\t\t ****** SZYBKIE ****** ");
	wyswietlCzasOrazInicjalizujTabliceRosnaco(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiSortowaniem_Szybkim(tab1, tab2, tab3, tab4, tab5);
	printf("\n###########################################################################################");
}

void wyswietlCzasOrazInicjalizujTabliceRosnaco(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]){
	int time = getCurrentTimeInMilliseconds();
	
	inicjalizujTabliceRosnaco(tab1, N_1);
	inicjalizujTabliceRosnaco(tab2, N_2);
	inicjalizujTabliceRosnaco(tab3, N_3);
	inicjalizujTabliceRosnaco(tab4, N_4);
	inicjalizujTabliceRosnaco(tab5, N_5);
	
	printf("\nCzas inicjalizacji tablic: %d ms", getCurrentTimeInMilliseconds()-time);
}

int getCurrentTimeInMilliseconds(){
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

void inicjalizujTabliceRosnaco(int tab [], int size){
		for (int i = 0; i < size; ++i)
			tab[i] = i+1;
}

void sprawdzTabliceWPrzypadkuPesymistycznym(){
	int tab1[N_1+1], tab2[N_2+1], tab3[N_3+1], tab4[N_4+1], tab5[N_5+1];
	
	printf("\n\n\n\n################################  PESYMISTYCZNY  ##########################################");
	printf("\n\t\t ****** WYBOR ****** ");
	wyswietlCzasOrazInicjalizujTabliceMalejaco(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiPrzez_Wybor(tab1, tab2, tab3, tab4, tab5);
	
	printf("\n\n\t\t ****** WSTAWIANIE ****** ");
	wyswietlCzasOrazInicjalizujTabliceMalejaco(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiPrzez_Wstawianie(tab1, tab2, tab3, tab4, tab5);
	
	printf("\n\n\t\t ****** SCALANIE ****** ");
	wyswietlCzasOrazInicjalizujTabliceMalejaco(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiPrzez_Scalanie(tab1, tab2, tab3, tab4, tab5);
	
	printf("\n\n\t\t ****** SZYBKIE ****** ");
	wyswietlCzasOrazInicjalizujTabliceMalejaco(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiSortowaniem_Szybkim(tab1, tab2, tab3, tab4, tab5);
	printf("\n#############################################################################################");
}

void wyswietlCzasOrazInicjalizujTabliceMalejaco(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]){
	int time = getCurrentTimeInMilliseconds();
	
	inicjalizujTabliceMalejaco(tab1, N_1);
	inicjalizujTabliceMalejaco(tab2, N_2);
	inicjalizujTabliceMalejaco(tab3, N_3);
	inicjalizujTabliceMalejaco(tab4, N_4);
	inicjalizujTabliceMalejaco(tab5, N_5);
	
	printf("\nCzas inicjalizacji tablic: %d ms", getCurrentTimeInMilliseconds()-time);
}

void sprawdzTabliceWPrzypadkuLosowym(){
	int tab1[N_1+1], tab2[N_2+1], tab3[N_3+1], tab4[N_4+1], tab5[N_5+1];
	
	printf("\n\n\n\n################################  LOSOWY  #################################################");
	printf("\n\n\t\t ****** WYBOR ****** ");
	wyswietlCzasOrazInicjalizujTabliceLosowo(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiPrzez_Wybor(tab1, tab2, tab3, tab4, tab5);
	
	printf("\n\n\t\t ****** WSTAWIANIE ****** ");
	wyswietlCzasOrazInicjalizujTabliceLosowo(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiPrzez_Wstawianie(tab1, tab2, tab3, tab4, tab5);
	
	printf("\n\n\t\t ****** SCALANIE ****** ");
	wyswietlCzasOrazInicjalizujTabliceLosowo(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiPrzez_Scalanie(tab1, tab2, tab3, tab4, tab5);
	
	printf("\n\n\t\t ****** SZYBKIE ****** ");
	wyswietlCzasOrazInicjalizujTabliceLosowo(tab1, tab2, tab3, tab4, tab5);
	posortujTabliceIWyswietlWynikiSortowaniem_Szybkim(tab1, tab2, tab3, tab4, tab5);
	printf("\n#############################################################################################");
}

void wyswietlCzasOrazInicjalizujTabliceLosowo(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]){
	int time = getCurrentTimeInMilliseconds();
	
	inicjalizujTabliceLosowo(tab1, N_1);
	inicjalizujTabliceLosowo(tab2, N_2);
	inicjalizujTabliceLosowo(tab3, N_3);
	inicjalizujTabliceLosowo(tab4, N_4);
	inicjalizujTabliceLosowo(tab5, N_5);
	printf("\nCzas inicjalizacji tablic: %d ms", getCurrentTimeInMilliseconds()-time);
}

void posortujTabliceIWyswietlWynikiPrzez_Wybor(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]){
	sortujPrzezWybor(tab1, N_1);
	sortujPrzezWybor(tab2, N_2);
	sortujPrzezWybor(tab3, N_3);
	sortujPrzezWybor(tab4, N_4);
	sortujPrzezWybor(tab5, N_5);
}

void sortujPrzezWybor(int tab [], int size){
	int time = getCurrentTimeInMilliseconds();
	unsigned long iloscOperacjiPodst = 0;
	
	for (int i = 0; i < size - 1; ++i){
		int min = i;
		for (int j = i + 1; j < size; ++j){
			++iloscOperacjiPodst;
			if (tab[min] > tab[j]){
				min = j;
			}
		}
		zamien(tab+min, tab+i);
		iloscOperacjiPodst += 3;
	}
	
	wyswietlInformacjeOSortowaniu(size, iloscOperacjiPodst, getCurrentTimeInMilliseconds()-time);
}

void zamien(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void wyswietlInformacjeOSortowaniu(int rozmiarTablicy, unsigned long iloscOperacji, unsigned int czas){
	int space1 = 15 - ileCyfrMaLiczba(rozmiarTablicy);
	int space2 = 15 - ileCyfrMaLiczba(iloscOperacji);
	printf("\nRozmiar Tablicy: %d %*s Operacje podstawowe: %lu %*s Czas: %u ms"
	, rozmiarTablicy, space1, "||", iloscOperacji, space2, "||", czas);
}

int ileCyfrMaLiczba(unsigned long liczba){
    int cyfry = 0;
    while (liczba) {
        liczba /= 10;
        cyfry++;
    }
    return cyfry;
}

void posortujTabliceIWyswietlWynikiPrzez_Wstawianie(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]){
	sortujPrzezWstawianie(tab1, N_1);
	sortujPrzezWstawianie(tab2, N_2);
	sortujPrzezWstawianie(tab3, N_3);
	sortujPrzezWstawianie(tab4, N_4);
	sortujPrzezWstawianie(tab5, N_5);
}

void sortujPrzezWstawianie(int tab [], int size){
	int time = getCurrentTimeInMilliseconds();
	unsigned long iloscOperacjiPodst = 0;
	
	for (int i = 1; i < size; ++i){
		int j = i;
		int temp = tab[i];
		iloscOperacjiPodst++;
		
		while(j > 0 && temp < tab[j-1]){
			tab[j] = tab[j-1];
			iloscOperacjiPodst += 2;
			--j;
		}
		tab[j] = temp;
	}
	
	wyswietlInformacjeOSortowaniu(size, iloscOperacjiPodst, getCurrentTimeInMilliseconds()-time);
}

void posortujTabliceIWyswietlWynikiPrzez_Scalanie(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]){
	uruchomSortowaniePrzezScalanieZeZliczaniemCzasuOrazIlosciOperacji(tab1, N_1);
	uruchomSortowaniePrzezScalanieZeZliczaniemCzasuOrazIlosciOperacji(tab2, N_2);
	uruchomSortowaniePrzezScalanieZeZliczaniemCzasuOrazIlosciOperacji(tab3, N_3);
	uruchomSortowaniePrzezScalanieZeZliczaniemCzasuOrazIlosciOperacji(tab4, N_4);
	uruchomSortowaniePrzezScalanieZeZliczaniemCzasuOrazIlosciOperacji(tab5, N_5);
}

void uruchomSortowaniePrzezScalanieZeZliczaniemCzasuOrazIlosciOperacji(int tab [], int size){
	unsigned long iloscOperacjiPodst = 0;
	int time = getCurrentTimeInMilliseconds();
	
	sortujPrzezScalanie(tab, 0, size-1, &iloscOperacjiPodst);
	wyswietlInformacjeOSortowaniu(size, iloscOperacjiPodst, getCurrentTimeInMilliseconds()-time);
}

void sortujPrzezScalanie(int tab [], int poczatek, int koniec, unsigned long *operacjePodst){
	
	if (koniec>poczatek){
		int srodek = (poczatek+koniec)/2;
		sortujPrzezScalanie(tab, poczatek, srodek, operacjePodst);
		sortujPrzezScalanie(tab, srodek+1, koniec, operacjePodst);
		scalTablice(tab, poczatek, srodek, koniec, operacjePodst);
	}
}

void scalTablice(int tab[], int poczatek, int srodek, int koniec, unsigned long *operacjePodst){
	int size_a = srodek - poczatek + 1;
	int size_b = koniec - srodek;
	
	int *tabLewa = (int *) malloc (sizeof(int)*(size_a+1));
	int *tabPrawa = (int *) malloc (sizeof(int)*(size_b+1));
	
	for (int i = 0; i < size_a; ++i){
		tabLewa[i] = tab[poczatek+i];
		++(*operacjePodst);
	}
	for (int i = 0; i < size_a; ++i){
		tabPrawa[i] = tab[srodek+i+1];
		++(*operacjePodst);
	}
		
	tabLewa[size_a] = tabPrawa[size_b-1]+1;
	tabPrawa[size_b] = tabLewa[size_a-1]+1;
	*operacjePodst += 2;
	
	int i = 0;
	int j = 0;
	for (int k = poczatek; k <= koniec; ++k){
		++(*operacjePodst);
		if (tabLewa[i] <= tabPrawa[j]){
			tab[k] = tabLewa[i];
			++(*operacjePodst);
			++i;
		}
		else{
			tab[k] = tabPrawa[j];
			++(*operacjePodst);
			++j;
		}
	}
	
	free(tabLewa);
	free(tabPrawa);
}

void posortujTabliceIWyswietlWynikiSortowaniem_Szybkim(int tab1[], int tab2[], int tab3[], int tab4[], int tab5[]){
	uruchomSortowanieSzybkieZeZliczaniemCzasuOrazIlosciOperacji(tab1, N_1);
	uruchomSortowanieSzybkieZeZliczaniemCzasuOrazIlosciOperacji(tab2, N_2);
	uruchomSortowanieSzybkieZeZliczaniemCzasuOrazIlosciOperacji(tab3, N_3);
	uruchomSortowanieSzybkieZeZliczaniemCzasuOrazIlosciOperacji(tab4, N_4);
	uruchomSortowanieSzybkieZeZliczaniemCzasuOrazIlosciOperacji(tab5, N_5);
}

void uruchomSortowanieSzybkieZeZliczaniemCzasuOrazIlosciOperacji(int tab [], int size){
	int time = getCurrentTimeInMilliseconds();
	unsigned long iloscOperacjiPodst = 0;
	sortowanieSzybkie(tab, 0, size-1, &iloscOperacjiPodst);
	wyswietlInformacjeOSortowaniu(size, iloscOperacjiPodst, getCurrentTimeInMilliseconds()-time);
}

void sortowanieSzybkie(int tab [], int poczatek, int koniec, unsigned long *operacjePodst){
	if(poczatek<koniec){
		int srodek = podzial(tab, poczatek, koniec, operacjePodst);
		sortowanieSzybkie(tab, poczatek, srodek-1, operacjePodst);
		sortowanieSzybkie(tab, srodek+1, koniec, operacjePodst);
	}
}

int podzial(int tab[], int poczatek, int koniec, unsigned long *operacjePodst){
	int mur = tab[koniec];
	++(*operacjePodst);
	int i = poczatek-1;
	for (int j = poczatek; j < koniec-1; ++j){
		++(*operacjePodst);
		if(tab[j] <= mur){
			++i;
			(*operacjePodst) += 3;
			zamien(tab+i, tab+j);
		}
	} 
	(*operacjePodst) += 3;
	zamien(tab+i+1, tab+koniec);
	return i+1;
}

void inicjalizujTabliceMalejaco(int tab [], int size){
	for (int i = 0; i < size; ++i)
		tab[i] = size-i;
}

void inicjalizujGeneratorLiczbPseudolosowych(){
	srand(time(NULL));
}

void inicjalizujTabliceLosowo(int tab [], int size){
		for (int i = 0; i < size; ++i)
			tab[i] = rand();
}

