<details>
<summary>Įdiegimo bei naudojimo instrukcija</summary>
<br>

## Projekto persikėlimas į savo kompiuterį

- Instaliuokite GitHub Desktop.
- Atsidarykite projekto [repozitorijos puslapį](https://github.com/low048/PirmasLaboratorinis).
- Paspauskite Code mygtuką ir pasirinkite Open with GitHub Desktop.
- Pasirinkite, kur norite išsaugoti projekto kopiją.
- Paspauskite Clone.


## Kompiliatorius

- Parsisiųskite [Cygwin](https://www.cygwin.com/setup-x86_64.exe).
- Instaliuokite Cygwin nepasirinkdami jokių pakuočių (packages), bet neištrinkite `setup-x86_64.exe`.
- Atidarykite cmd, ir įvykdykite šias komandas:
    - `cd C:\failo\vieta\kompiuteryje` (pvz. "cd C:\Users\User\Downloads", kuriame yra setup-x86_64.exe).
    - `setup-x86_64.exe -q -P wget -P gcc-g++ -P make -P diffutils -P libmpfr-devel -P libgmp-devel -P libmpc-devel`
- Palaukite kol užsidarys naujai atidarytas langas, tada bus įdiegtos visos reikiamos pakuotės programos paleidimui.

## Projekto kompiliavimas

- Atsidarykite `Cygwin64 Terminal`, tada jame įveskite:
    - `cd "C:\projekto\vieta\kompiuteryje"` (pvz. "cd C:\Users\User\Desktop\PirmasLaboratorinis", kuriame yra projekto kopija).
<br>Galimų tolesnių komandų sąrašas:
    - `make vector` - jei norite kompiliuoti tik `vector` programos versiją
    - `make list` - jei norite kompiliuoti tik `list` programos versiją
    - `make deque`- jei norite kompiliuoti tik `deque` programos versiją
    - `make all` - jei norite kompiliuoti visas anskčiau minėtas versijas
    - `make clean`- jei norite ištrinti visas kompiliuotas versijas

## Programos naudojimas

- Atsidarykite naujai sukompiliuotą programos versiją(-as).
- Sekite instrukcijas, kurios rodomos konsolės langelyje.

Programos paleidimo pavyzdys:
![pvz](https://raw.githubusercontent.com/low048/PirmasLaboratorinis/V1.0/TyrimuNuotraukos/KetvirtasTyrimas/1_strategija/list/1.png)

</details>

<details open>
<summary>Testavimas</summary>
<br>

Kompiuterio parametrai: 
- Ryzen 5 6600HS
- NVME SSD
- 16 GB LPDDR5 6400 MHz RAM

Kiekvieno programos paleidimo tyrimų metu nuotraukas galite matyti [čia](https://github.com/low048/PirmasLaboratorinis/tree/V1.0/TyrimuNuotraukos/).

Testavimas buvo atliktas su failais:
- `studentai_1000.txt` - 1k stud., 15 n.d., 197 KB (iš savos atsitiktinių studentų failo generavimo funkcijos)
- `studentai10000.txt` - 10k stud., 15 n.d., 2,022 KB (iš anksto generuotas, patalpintas VMA)
- `studentai100000.txt` - 100k stud., 20 n.d., 25,098 KB (iš anksto generuotas, patalpintas VMA)
- `studentai1000000.txt` - 1 mil. stud., 7 n.d., 124,024 KB (iš anksto generuotas, patalpintas VMA)
- `studentai_10000000.txt` - 10 mil. stud., 15 n.d., 1,962,891 KB (iš savos atsitiktinių studentų failo generavimo funkcijos)

# Testavimo rezultatai (v1.0)

## 3-as tyrimas - veiksmų su įvairaus dydžio failais veikimo spartos palyginimas naudojant skirtingus konteinerius
### std::vector:

| Veiksmas                                 | studentai_1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai_1000000.txt |
|------------------------------------------|--------------------|--------------------|---------------------|----------------------|-----------------------|
| Duomenų nuskaitymas                      | 0.0079811          | 0.0487976          | 0.531535            | 2.61098              | 40.1398               |
| Studentų rūšiavimas į dvi grupes         | 0.0003127          | 0.0032477          | 0.0311697           | 0.40542              | 2.92201               |
| Studentų rikiavimas (pagal galutinį vid.)| 0.0012382          | 0.0124778          | 0.183998            | 2.35545              | 33.5949               |
| Nepatenkinamų stud. įrašymas             | 0.0135206          | 0.0074135          | 0.0548416           | 0.52273              | 4.82187               |
| Patenkinamų stud. įrašymas               | 0.0023206          | 0.0117405          | 0.0714214           | 0.95434              | 7.61723               |
| Visas laikas (be įvesties)               | 0.0263308          | 0.0848641          | 0.87404             | 6.84993              | 89.0968               |

`std::vector` suteikia greitą atsitiktinę prieigą ir yra efektyvus pridedant/pašalinant elementus konteinerio gale, tačiau lėčiau vyksta rikiavimas.

### std::list:

| Veiksmas                                 | studentai_1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai_1000000.txt |
|------------------------------------------|--------------------|--------------------|---------------------|----------------------|-----------------------|
| Duomenų nuskaitymas                      | 0.005016           | 0.0542886          | 0.554947            | 2.57551              | 40.0213               |
| Studentų rūšiavimas į dvi grupes         | 0.0002704          | 0.0027486          | 0.0294175           | 0.304561             | 2.68456               |
| Studentų rikiavimas (pagal galutinį vid.)| 0.0003741          | 0.0046876          | 0.0601057           | 0.916619             | 15.4971               |
| Nepatenkinamų stud. įrašymas             | 0.0023782          | 0.0082674          | 0.069381            | 0.561922             | 23.1234               |
| Patenkinamų stud. įrašymas               | 0.0021207          | 0.0129539          | 0.0906158           | 0.897952             | 7.86134               |
| Visas laikas (be įvesties)               | 0.0110467          | 0.0840572          | 0.805627            | 5.25787              | 89.1898               |

`std::list` yra dvipusis sąrašas, kuris leidžia greitai įterpti ir pašalinti elementus bet kurioje vietoje. Tačiau, kadangi elementai nėra saugomi gretimuose atminties blokuose, atsitiktinė prieiga yra lėta.

### std::deque:

| Veiksmas                                 | studentai_1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai_1000000.txt |
|------------------------------------------|--------------------|--------------------|---------------------|----------------------|-----------------------|
| Duomenų nuskaitymas                      | 0.0047706          | 0.0471314          | 0.516918            | 2.47154              | 39.3773               |
| Studentų rūšiavimas į dvi grupes         | 0.0002705          | 0.0027023          | 0.0244668           | 0.243373             | 2.14507               |
| Studentų rikiavimas (pagal galutinį vid.)| 0.0014055          | 0.0162116          | 0.226202            | 2.95295              | 41.2255               |
| Nepatenkinamų stud. įrašymas             | 0.0026466          | 0.0094148          | 0.0765059           | 0.734575             | 7.40374               |
| Patenkinamų stud. įrašymas               | 0.002045           | 0.0122805          | 0.107698            | 0.976536             | 10.6144               |
| Visas laikas (be įvesties)               | 0.01218            | 0.0890443          | 0.952917            | 7.38004              | 100.768               |

`std::deque` yra kaip tarpinė būsena tarp `std::vector` ir `std::list`. Jis leidžia greitai pridėti ir pašalinti elementus tiek priekyje, tiek gale, bet atsitiktinė prieiga yra šiek tiek lėtesnė nei std::vector.


## 4-as tyrimas - rūšiavimo realizacijų veikimo spartos palyginimas

### 1 strategija - du nauji to paties tipo konteineriai

| Failas               | std::vector | std::list  | std::deque |
|----------------------|-------------|------------|------------|
| studentai_1000.txt   | 0.0003127   | 0.0002704  | 0.0002705  |
| studentai10000.txt   | 0.0032477   | 0.0027486  | 0.0027023  |
| studentai100000.txt  | 0.0311697   | 0.0294175  | 0.0244668  |
| studentai1000000.txt | 0.40542     | 0.304561   | 0.243373   |
| studentai_1000000.txt| 2.92201     | 2.68456    | 2.14507    |

### 2 strategija - tik vienas naujas nepatenkinamų studentų konteineris

| Failas               | std::vector | std::list  | std::deque |
|----------------------|-------------|------------|------------|
| studentai_1000.txt   | 0.0012996   | 0.0006707  | 0.0015146  |
| studentai10000.txt   | 0.200978    | 0.0067772  | 0.0175728  |
| studentai100000.txt  | 0.22196     | 0.0954995  | 0.248444   |
| studentai1000000.txt | 2.58776     | 1.25379    | 3.08339    |
| studentai_1000000.txt| 36.8585     | 20.8087    | 41.5902    |

Visose realizacijose rūšiavimas vyksta lėčiau, tačiau tai yra daug efektyviau atminties naudojimo atžvilgiu.

### 3 strategija - naudojamos optimizacijos 2-ai strategijai pagerinti

Kadangi 1-osios strategijos konteinerių veikimą **pateiktais** algoritmais nelabai būtų galima pagreitinti, pasirinkau optimizuoti 2-ąją strategiją, nes ši iš pradžių buvo itin lėta.

Optimizacijai panaudojau `std::partition` algoritmą, kuris su predikatu pertvarko vektoriaus elementus taip, kad patenkinami būtų priekyje, o nepatenkinami gale. Tokiu būdu išvengiama pakartotinų `erase` operacijų, kuri šiems konteineriams yra brangi, nes reikia pertvarkyti visus elementus taip, kad būtų užpildomas naujai atsiradęs tarpas. Taip pat konteinerio elementai yra perkeliami naudojant `std::make_move_iterator`, kad nereikėtų jų kopijuoti.

| Failas               | std::vector | std::list  | std::deque |
|----------------------|-------------|------------|------------|
| studentai_1000.txt   | 0.0001595   | 0.0002096  | 0.000229   |
| studentai10000.txt   | 0.0016814   | 0.0021475  | 0.0020181  |
| studentai100000.txt  | 0.0172146   | 0.0208541  | 0.0218965  |
| studentai1000000.txt | 0.132258    | 0.194196   | 0.197143   |
| studentai_1000000.txt| 1.33541     | 1.81953    | 1.93628    |

# Testavimo rezultatai (SENA VERSIJA - v0.4)
## 1-as tyrimas – atsitiktinių studentų failų generavimas

Kiekvienam failui generuojama 15 namų darbų pažymių.

| Bandymo nr. | 1,000 (s)  | 10,000 (s)    | 100,000 (s)   | 1,000,000 (s) | 10,000,000 (s) |
|------------|-------------|---------------|---------------|---------------|----------------|
| #1         | 0.0122881   | 0.0562507     | 0.525285      | 5.12021       | 50.9886        |
| #2         | 0.0065812   | 0.0552215     | 0.487528      | 4.86378       | 47.3717        |
| #3         | 0.0060949   | 0.0546876     | 0.495838      | 4.73056       | 50.3248        |
| Avg        | 0.0083214   | 0.0553866     | 0.5028837     | 4.90485       | 49.5617        |

## 2-as tyrimas – veiksmai su įvairaus dydžio failais

| Veiksmas                                 | studentai_1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai_1000000.txt |
|------------------------------------------|--------------------|--------------------|---------------------|----------------------|-----------------------|
| Duomenų nuskaitymas                      | 0.004684           | 0.0439758          | 0.525648            | 2.51385              | 40.7778               |
| Studentų rūšiavimas į dvi grupes         | 0.000408           | 0.003108           | 0.0323843           | 0.319982             | 3.22454               |
| Studentų rikiavimas (pagal galutinį vid.)| 0.0014113          | 0.0134936          | 0.195734            | 2.53566              | 36.1703               |
| Nepatenkinamų stud. įrašymas             | 0.0022855          | 0.0060508          | 0.0517857           | 0.49798              | 5.58282               |
| Patenkinamų stud. įrašymas               | 0.0013947          | 0.0082172          | 0.0670584           | 0.60272              | 7.11938               |
| Visas laikas (be įvesties)               | 0.0112775          | 0.0763587          | 0.875746            | 6.4748               | 92.8779               |

# Testavimo rezultatai (SENA VERSIJA - v0.2)

## Preliminarus tyrimas
### Failo nuskaitymas

| Bandymo nr. | 10k (s) | 100k (s) | 1 mil (s) |
|-------------|---------|----------|-----------|
| #1          | 0.04551 | 0.54182  | 2.57977   |
| #2          | 0.04652 | 0.53072  | 2.56835   |
| #3          | 0.05092 | 0.54170  | 2.55759   |
| Avg         | 0.04765 | 0.53808  | 2.56857   |

### Rikiavimas pagal 3-ią pasirinkimą (galutinis pažymys, vid.)

| Bandymo nr.  | 10k (s) | 100k (s) | 1 mil (s) |
|--------------|---------|----------|-----------|
| #1           | 0.01309 | 0.16808  | 2.18078   |
| #2           | 0.01324 | 0.17555  | 2.23208   |
| #3           | 0.01122 | 0.17587  | 2.11809   |
| Avg          | 0.01252 | 0.17317  | 2.17698   |

</details>
