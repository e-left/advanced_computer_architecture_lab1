Ach Lab2

# 1o
L1 instruction   *=> size=32768 ~> 32KB*

associativity *assoc=2*

L1 Data caches  *=> size=65536 ~> 65 KB*

associativity *assoc=2*

L2 cache *size=2097152  ~>  2MB*

associativity *assoc=8*

cache line	cache\_line\_size=64

# 2o

## Specbzip
1) χρόνο εκτέλεσης			*sim\_seconds  =  0.083982*
1) CPI 					*system.cpu.cpi  =  1.679650*

1) συνολικά miss rates για την L1 Instruction cache *system.cpu.icache.overall\_miss\_rate::total     0.000077*

1) συνολικά miss rates για την L1 Data cache *system.cpu.dcache.overall\_miss\_rate::total     0.014798*

1) συνολικά miss rates για την L2 cache 

*system.l2.overall\_miss\_rate::total           0.282163*

## Specmcf
1) χρόνο εκτέλεσης			*sim\_seconds  =  0.064955*
1) CPI 					*system.cpu.cpi  =  1.299095*

1) συνολικά miss rates για την L1 Instruction cache *system.cpu.icache.overall\_miss\_rate::total     0.023612*

1) συνολικά miss rates για την L1 Data cache *system.cpu.dcache.overall\_miss\_rate::total     0.002108*

1) συνολικά miss rates για την L2 cache 

*system.l2.overall\_miss\_rate::total           0.055046*

## Spechmmer
1) χρόνο εκτέλεσης			*sim\_seconds  =  0.059396*
1) CPI 					*system.cpu.cpi  =  1.187917*

1) συνολικά miss rates για την L1 Instruction cache *system.cpu.icache.overall\_miss\_rate::total     0.000221*

1) συνολικά miss rates για την L1 Data cache *system.cpu.dcache.overall\_miss\_rate::total     0.001637*

1) συνολικά miss rates για την L2 cache 

*system.l2.overall\_miss\_rate::total           0.077760*

## Specsjeng
1) χρόνο εκτέλεσης:			*sim\_seconds  =  0.513528*
1) CPI: 					*system.cpu.cpi  =  10.270554*

1) συνολικά miss rates για την L1 Instruction cache: *system.cpu.icache.overall\_miss\_rate::total     0.000020*

1) συνολικά miss rates για την L1 Data cache: *system.cpu.dcache.overall\_miss\_rate::total     0.121831*

1) συνολικά miss rates για την L2 cache: 

*system.l2.overall\_miss\_rate::total           0.999972*

## Speclibm
1) χρόνο εκτέλεσης:			*sim\_seconds  =  0.174671*
1) CPI: 					*system.cpu.cpi  =* *3.493415*

1) συνολικά miss rates για την L1 Instruction cache: *system.cpu.icache.overall\_miss\_rate::total     0.000094*

1) συνολικά miss rates για την L1 Data cache: *system.cpu.dcache.overall\_miss\_rate::total     0.060972*

1) συνολικά miss rates για την L2 cache: 

*system.l2.overall\_miss\_rate::total           0.999944*


|<h2></h2>|<h2>Specbzip</h2>|<h2>Specmcf</h2>|<h2>Spechmmer</h2>|<h2>Specsjeng</h2>|<h2>Speclibm</h2>|
| :- | :- | :- | :- | :- | :- |
|χρόνος εκτέλεσης|0.083982|0.064955|0.059396|0.513528|0.174671|


|<h2></h2>|<h2>Specbzip</h2>|<h2>Specmcf</h2>|<h2>Spechmmer</h2>|<h2>Specsjeng</h2>|<h2>Speclibm</h2>|
| :- | :- | :- | :- | :- | :- |
|CPI|1.679650|1.299095|1.187917|10.270554|3.493415|


|<h2></h2>|<h2>Specbzip</h2>|<h2>Specmcf</h2>|<h2>Spechmmer</h2>|<h2>Specsjeng</h2>|<h2>Speclibm</h2>|
| :- | :- | :- | :- | :- | :- |
|*Icache\_miss\_rate::total*|0.000077|0.023612|0.000221|0.000020|0.000094|


|<h2></h2>|<h2>Specbzip</h2>|<h2>Specmcf</h2>|<h2>Spechmmer</h2>|<h2>Specsjeng</h2>|<h2>Speclibm</h2>|
| :- | :- | :- | :- | :- | :- |
|*dcache\_miss\_rate::total*|0.014798|0.002108|0.001637|0.121831|0.060972|


|<h2></h2>|<h2>Specbzip</h2>|<h2>Specmcf</h2>|<h2>Spechmmer</h2>|<h2>Specsjeng</h2>|<h2>Speclibm</h2>|
| :- | :- | :- | :- | :- | :- |
|*l2\_miss\_rate::total*|0.282163|0.055046|0.077760|0.999972|0.999944|

![](Aspose.Words.f3488851-f0ed-4cf6-b351-049795c663bc.001.png)

1.	Ο χρόνος εκτέλεσης του specsjeng είναι πολύ μεγαλύτερος από των άλλων

![](Aspose.Words.f3488851-f0ed-4cf6-b351-049795c663bc.002.png)

2.	Το CPI του specsjeng είναι πολύ μεγαλύτερο από των άλλων


![](Aspose.Words.f3488851-f0ed-4cf6-b351-049795c663bc.003.png)

3.	Όμως το miss rate των instructions του specmcf είναι πολύ μεγαλύτερο από των άλλων

![](Aspose.Words.f3488851-f0ed-4cf6-b351-049795c663bc.004.png)

4.	Το miss rate των data του specsjeng είναι πολύ μεγαλύτερο από των άλλων


![](Aspose.Words.f3488851-f0ed-4cf6-b351-049795c663bc.005.png)

5.	Το miss rate στην L2 του specsjeng και του speclibm είναι πολύ μεγαλύτερα από των άλλων

Λόγω του 5 και του 4 είναι λογικό να προκύψει μεγάλο CPI για το specsjeng, άρα και μεγάλος χρόνος εκτέλεσης.
# 4o
## Specbzip
1) χρόνο εκτέλεσης:			*sim\_seconds  =  0.083609*
1) CPI: 					*system.cpu.cpi  =  1.672175*

1) συνολικά miss rates για την L1 Instruction cache: *system.cpu.icache.overall\_miss\_rate::total     0.000077*

1) συνολικά miss rates για την L1 Data cache: *system.cpu.dcache.overall\_miss\_rate::total     0.014795*

1) συνολικά miss rates για την L2 cache: 

*system.l2.overall\_miss\_rate::total           0.282159*


|<h2></h2>|<h2>Specbzip</h2>|<h2>Specbzip(fast DDR)</h2>|<h2>%</h2>|
| :- | :- | :- | :- |
|χρόνος εκτέλεσης|0.083982|0.083609|-0.4441|
|` `CPI|1.679650|1.672175|-0.4465|
|*Icache\_miss\_rate::total*|0.000077|0.000077|0|
|*dcache\_miss\_rate::total*|0.014798|0.014795|-0.02|
|*l2\_miss\_rate::total*|0.282163|0.282159|-0.0014|



Παρατηρούμε ότι με την αύξηση της συχνότητας της μνήμη μειώνεται το miss rate για την L2 και την L1 data cache. Αυτό είναι λογικό διότι αυτές οι caches θα λαμβάνουν δεδομένα πιο γρήγορα, άρα θα έχουμε λιγότερα misses στον ίδιο χρόνο. Αυτό έχει επίδραση στο CPI, που είναι λογικό, και φυσικά το CPI όπως φάνηκε και προηγουμένως επηρεάζει σχεδόν ανάλογα τον χρόνο εκτέλεσης.

