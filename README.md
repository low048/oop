# Testavimo rezultatai

Testavimas buvo atliktas su iš anksto generuotais failais, turinčiais 10k (`studentai10000.txt`), 100k (`studentai100000.txt`) ir 1 mil (`studentai1000000.txt`) studentų.

Kompiuterio parametrai: 
- Ryzen 5 6600HS
- NVME SSD
- 16 GB LPDDR5 6400 MHz RAM

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
