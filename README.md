Kompiuterio parametrai: 
- Ryzen 5 6600HS
- NVME SSD
- 16 GB LPDDR5 6400 MHz RAM

# Testavimo rezultatai (v0.4)
## 1-as tyrimas

Kiekvieno programos paleidimo tyrimo metu nuotraukas galite matyti [čia](https://github.com/low048/PirmasLaboratorinis/tree/V0.4/TyrimuNuotraukos/PirmasTyrimas).

| Bandymo Nr | 1,000     | 10,000    | 100,000   | 1,000,000 | 10,000,000 |
|------------|-----------|-----------|-----------|-----------|------------|
| #1         | 0.0122881 | 0.0562507 | 0.525285  | 5.12021   | 50.9886    |
| #2         | 0.0065812 | 0.0552215 | 0.487528  | 4.86378   | 47.3717    |
| #3         | 0.0060949 | 0.0546876 | 0.495838  | 4.73056   | 50.3248    |
| Avg        | 0.0083214 | 0.0553866 | 0.5028837 | 4.90485   | 49.5617    |

## 2-as tyrimas

Kiekvieno programos paleidimo tyrimo metu nuotraukas galite matyti [čia](https://github.com/low048/PirmasLaboratorinis/tree/V0.4/TyrimuNuotraukos/AntrasTyrimas).

Testavimas buvo atliktas su failais:
- `studentai_1000.txt` - 1k stud., 15 n.d., 197 KB (iš savos atsitiktinių studentų failo generavimo funkcijos)
- `studentai10000.txt` - 10k stud., 15 n.d., 2,022 KB (iš anksto generuotas, patalpintas VMA)
- `studentai100000.txt` - 100k stud., 15 n.d., 25,098 KB (iš anksto generuotas, patalpintas VMA)
- `studentai1000000.txt` - 1 mil. stud., 15 n.d., 124,024 KB (iš anksto generuotas, patalpintas VMA)
- `studentai_10000000.txt` - 10 mil. stud., 15 n.d., 1,962,891 KB (iš savos atsitiktinių studentų failo generavimo funkcijos)

| Veiksmas                                 | studentai_1000.txt | studentai10000.txt | studentai100000.txt | studentai1000000.txt | studentai_1000000.txt |
|------------------------------------------|--------------------|--------------------|---------------------|----------------------|-----------------------|
| Duomenų nuskaitymas                      | 0.004684           | 0.0439758          | 0.525648            | 2.51385              | 40.7778               |
| Studentų rūšiavimas į dvi grupes         | 0.000408           | 0.003108           | 0.0323843           | 0.319982             | 3.22454               |
| Studentų rikiavimas (pagal galutinį vid.)| 0.0014113          | 0.0134936          | 0.195734            | 2.53566              | 36.1703               |
| Nepatenkinamų stud. įrašymas             | 0.0022855          | 0.0060508          | 0.0517857           | 0.49798              | 5.58282               |
| Patenkinamų stud. įrašymas               | 0.0013947          | 0.0082172          | 0.0670584           | 0.60272              | 7.11938               |
| Visas laikas (be įvesties)               | 0.0112775          | 0.0763587          | 0.875746            | 6.4748               | 92.8779               |

# Testavimo rezultatai (SENA VERSIJA - v0.2)

Testavimas buvo atliktas su iš anksto generuotais failais, kurie buvo patalpinti VMA:
- `studentai10000.txt`
- `studentai100000.txt`
- `studentai1000000.txt`

## Failo nuskaitymas

| Bandymas | 10k (s) | 100k (s) | 1 mil (s) |
|----------|---------|----------|-----------|
| #1       | 0.04551 | 0.54182  | 2.57977   |
| #2       | 0.04652 | 0.53072  | 2.56835   |
| #3       | 0.05092 | 0.54170  | 2.55759   |

**Vidurkis:**
- 10k: 0.04765 s
- 100k: 0.53808 s
- 1 mil: 2.56857 s

## Rikiavimas pagal 3 pasirinkimą (galutinis pažymys, vid.)

| Bandymas | 10k (s) | 100k (s) | 1 mil (s) |
|----------|---------|----------|-----------|
| #1       | 0.01309 | 0.16808  | 2.18078   |
| #2       | 0.01324 | 0.17555  | 2.23208   |
| #3       | 0.01122 | 0.17587  | 2.11809   |

**Vidurkis:**
- 10k: 0.01252 s
- 100k: 0.17317 s
- 1 mil: 2.17698 s
