<details open>
<summary>Testavimas</summary>
<br>

Kompiuterio parametrai: 
- Ryzen 5 6600HS
- NVME SSD
- 16 GB LPDDR5 6400 MHz RAM

Kiekvieno programos paleidimo tyrimų metu nuotraukas galite matyti [čia](https://github.com/low048/PirmasLaboratorinis/tree/V0.4/TyrimuNuotraukos/).

Testavimas buvo atliktas su failais:
- `studentai_1000.txt` - 1k stud., 15 n.d., 197 KB (iš savos atsitiktinių studentų failo generavimo funkcijos)
- `studentai10000.txt` - 10k stud., 15 n.d., 2,022 KB (iš anksto generuotas, patalpintas VMA)
- `studentai100000.txt` - 100k stud., 15 n.d., 25,098 KB (iš anksto generuotas, patalpintas VMA)
- `studentai1000000.txt` - 1 mil. stud., 15 n.d., 124,024 KB (iš anksto generuotas, patalpintas VMA)
- `studentai_10000000.txt` - 10 mil. stud., 15 n.d., 1,962,891 KB (iš savos atsitiktinių studentų failo generavimo funkcijos)

# Testavimo rezultatai (v1.0)

## 3-as tyrimas - veiksmų su įvairaus dydžio failais veikimo spartos palyginimas naudojant skirtingus konteinerius
### vector:

| Veiksmas                                 | studentai_1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai_1000000.txt |
|------------------------------------------|--------------------|--------------------|---------------------|----------------------|-----------------------|
| Duomenų nuskaitymas                      | 0.0079811          | 0.0487976          | 0.531535            | 2.61098              | 40.1398               |
| Studentų rūšiavimas į dvi grupes         | 0.0003127          | 0.0032477          | 0.0311697           | 0.40542              | 2.92201               |
| Studentų rikiavimas (pagal galutinį vid.)| 0.0012382          | 0.0124778          | 0.183998            | 2.35545              | 33.5949               |
| Nepatenkinamų stud. įrašymas             | 0.0135206          | 0.0074135          | 0.0548416           | 0.52273              | 4.82187               |
| Patenkinamų stud. įrašymas               | 0.0023206          | 0.0117405          | 0.0714214           | 0.95434              | 7.61723               |
| Visas laikas (be įvesties)               | 0.0263308          | 0.0848641          | 0.87404             | 6.84993              | 89.0968               |

`std::vector` suteikia greitą atsitiktinę prieigą ir yra efektyvus pridedant/pašalinant elementus konteinerio gale, tačiau lėčiau vyksta rikiavimas.

### list:

| Veiksmas                                 | studentai_1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai_1000000.txt |
|------------------------------------------|--------------------|--------------------|---------------------|----------------------|-----------------------|
| Duomenų nuskaitymas                      | 0.005016           | 0.0542886          | 0.554947            | 2.57551              | 40.0213               |
| Studentų rūšiavimas į dvi grupes         | 0.0002704          | 0.0027486          | 0.0294175           | 0.304561             | 2.68456               |
| Studentų rikiavimas (pagal galutinį vid.)| 0.0003741          | 0.0046876          | 0.0601057           | 0.916619             | 15.4971               |
| Nepatenkinamų stud. įrašymas             | 0.0023782          | 0.0082674          | 0.069381            | 0.561922             | 23.1234               |
| Patenkinamų stud. įrašymas               | 0.0021207          | 0.0129539          | 0.0906158           | 0.897952             | 7.86134               |
| Visas laikas (be įvesties)               | 0.0110467          | 0.0840572          | 0.805627            | 5.25787              | 89.1898               |

`std::list` yra dvipusis sąrašas, kuris leidžia greitai įterpti ir pašalinti elementus bet kurioje vietoje. Tačiau, kadangi elementai nėra saugomi gretimuose atminties blokuose, atsitiktinė prieiga yra lėta.

### deque:

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
| studentai_1000.txt   | 0.0160035   | 0.000119   | 0.0064141  |
| studentai10000.txt   | 1.3132      | 0.0014248  | 0.561508   |
| studentai100000.txt  | 260.609     | 0.010907   | 62.2927    |
| studentai1000000.txt | n/a         | 0.108521   | n/a        |
| studentai_1000000.txt| n/a         | 1.00361    | n/a        |

`n/a` - užtruko per ilgai.

`std::vector` ir `std::deque` realizacijos buvo ženkliai lėtesnės, o `std::list` net pagreitėjo.


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

| Bandymas nr. | 10k (s) | 100k (s) | 1 mil (s) |
|--------------|---------|----------|-----------|
| #1           | 0.01309 | 0.16808  | 2.18078   |
| #2           | 0.01324 | 0.17555  | 2.23208   |
| #3           | 0.01122 | 0.17587  | 2.11809   |
| Avg          | 0.01252 | 0.17317  | 2.17698   |

</details>
