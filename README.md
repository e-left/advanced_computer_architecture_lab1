# This repo serves as the report and codebase for Lab 1/3 for the Advanced Computer Architecture course, on the Electrical and Computer Engineering school of Aristotle University of Thessaloniki

Ανδρονίκου Δημήτρης, 9836

Αλεξανδρίδης Φώτιος, 9953

---
## Advaced Computer Architecture, Lab 01

### Question 1

While running the command:
```
$ ./build/ARM/gem5.opt -d hello_result configs/example/arm/starter_se.py --cpu="minor" "tests/test-progs/hello/bin/arm/linux/hello"
```
we can see that we specify the CPU type to be `minor`. Other options are `atomic` and `hpi`, which we can see defined on the dictionary called `cpu_types`, defined on lines 61-69 on `starter_se.py`. We can also see that we define the cache line size to be 64 in line 78.

Other parameters we can provide:
- CPU frequency, for which the default is 4GHz 
- Number of CPU cores, with the default being 1
- Type of main memory, with the default being a DDR3 1600 MHz 8x8 Gigabytes
- Channels of main memory, with the default being two
- Number of memory ranks per channel, default being None (0)
- Physical memory size, with the default being 2 GB

Moreover, there are two more defaults set up by `gem5`. The global operating frequency of the simulation is 1GHz, defined on line 90, and the voltage domain used in the simulated CPU is 3.3 volts, defined on line 89.

Moreover, the CPU type also influences the type of L1 and L2 cache. For the `minor` CPU type we have the following configuration:

| L1 icache | L1 dcache | L2 cache | Walk Cache |
| --- | --- | --- | --- | 
| `devices.L1I` | `devices.L1D` | `devices.L2` | None (nothing present in the dictionary) |

### Question 2

#### Subquestion a
Opening the `config.ini` file, we can check right away the main memory size (found in the `mem_ranges` entry, line 21), the fact that our system uses two channels for the main memory (two entries on line 22), the number of threads (1, on line 114). We can also find information for the L1 and L2 cache configuration in the fields `system.cpu_cluster.cpus.dcache` and `system.cpu_cluster.l2`. We can also determine the cache line size from the field `system -> cache_line_size` to be 64.
Finally we can determine the system frequency to be 1 GHz from the field `system.clk_domain -> clock` which is 1000 (in ticks AKA picoseconds in the current configuration).

#### Subquestion b
TODO: add values here
`simSeconds` is the number of seconds simulated, `simInsts` is the number of instructions simulated, and `hostInstRate` is the simulator instruction rate per second.

#### Subquestion c
In total there are 5834 comitted operations, found in the field `system.cpu_cluster.cpus.numOps`, and 5028 commited instructions, found in the field `system.cpu_cluster.cpus.numInsts`. The reason that the number of committed operations is larger than the number of committed instructions is that each instruction can be further broken down to multiple micro operations (micro-op), and as such the number of committed operations will always be greater than or equal to the number of
committed instructions.

#### Subquestion d
In total, the L2 cache was accessed 7884 times, found in the `system.cpu_cluster.l2.tags.dataAccesses` field. Alternatively, we know that 
L2 data access count is the same as L1 miss count

### Question 3

The different in-order CPU types are:

- SimpleCPU: The SimpleCPU is a purely functional, in-order model that is suited for cases where a detailed model is not necessary. This can include warm-up periods, client systems that are driving a host, or just testing to make sure a program works. It is now broken up into three classes, the BaseSimpleCPU, the AtomicSimpleCPU and the TimingSimpleCPU.

- MinorCPU: Minor is an in-order processor model with a fixed pipeline but configurable data structures and execute behaviour. It is intended to be used to model processors with strict in-order execution behaviour and allows visualisation of an instruction's position in the pipeline through the MinorTrace/minorview.py format/tool. The intention is to provide a framework for micro-architecturally correlating the model with a particular, chosen processor with similar capabilities.

- HPI: The HPI model is tuned to be representative of a state of the art ARMv8-A in order CPU. This model uses the same 4 stage pipeline model as the MinorCPU. 

#### Subquestions

The program we will be executing is a simple recursive fibonacci calculator for the first 28 fibonacci numbers. Its source code can be found in `lab1/fib.c`

| CPU Type | Default configuration | 1 GHz CPU Frequency | DDR4\_2400\_8x8 memory controller | 
| --- | --- | --- | --- |
| MinorCPU | 0.012250 | 0.024471 | 0.012249 |
| TimingSimpleCPU | 0.023691 | 0.047353 | 0.023690 |

##### Notes 
All times are in seconds. Default configuration includes a 2 GHz CPU frequency, and a DDR3\_1600\_8x8 memory controller. When halving the CPU frequency, we can see that the execution time approximately doubles, which makes sense if we define $frequency = 1 / time$. Changing the memory controller has an almost insignificant impact to the execution time, due to the benchmarking program using close to none variables. Also the MinorCPU is faster than the TimingSimpleCPU in general because it
utilizes a pipeline, while the other one does not.


### Lab 01 assignment review

TODO: change this
In general, the hardest part of this assignment was the toolchain setup. After that was done, the next obstacle was the large size of the output files(for the hello world example the `config.ini` file has 1537 lines, and the `stats.txt` file has 1181 lines), and as such parsing them and retrieving the requested information was time consuming. Finally, the example benchmark program should benchmark more aspects of memory, and as such a guideline for that would be useful (e.g. a program
that stores a large amount of data in memory, or that reads different memory locations frequently, thus interacting frequently with cache), in order for this first lab to not be too time consuming, since the focus of this lab is to set up an environment, familiarize ourselves with the tools we are going to use, and develop a robust testing/simulating setup (automate cross compilation, execution with parametrizable bash/python scripts). The gem5 documentation is really helpful and
detailed to the extent needed (provides the user with sensible defaults and bite-sized portions of information when starting out). 

---
## Advaced Computer Architecture, Lab 02

### Question 1

#### Subquestion c

`system.clk_domain.clock` entry
| | 401.bzip2 | 429.mcf | 456.hmmer | 458.sjeng | 470.lbm | 
| --- | --- | --- | --- | -- | --- |
| default | 1000 | 1000 | 1000 | 1000 | 1000 |
| 1GHz | 1000 | 1000 | 1000 | 1000 | 1000 |
| 3GHz | 1000 | 1000 | 1000 | 1000 | 1000 |

`cpu_cluster.clk_domain.clock` entry
| | 401.bzip2 | 429.mcf | 456.hmmer | 458.sjeng | 470.lbm | 
| --- | --- | --- | --- | -- | --- |
| default | 500 | 500 | 500 | 500 | 500 |
| 1GHz | 1000 | 1000 | 1000 | 1000 | 1000 |
| 3GHz | 333 | 333 | 333 | 333 | 333 |

To answer the theretical questions, we will focus on the first benchmark, but the same information is appliccable for all benchmarks.
We observe that the system clock entry defines the clock rate for the total system, the components of the motherboard. The CPU clock is responsible for defining the clock rate for the different CPU components. Because a CPU usually has to perform more operations per unit of time compared to the other components, the CPU clock is usually defined to be at least as fast as the system clock, but usually faster. For performance and syncronization reasons, we actually want the system clock rate in
ticks to be an integral product of the CPU clock rate in ticks. By inspecting the `config.json` file for a 1GHz benchmark, we can observe that the different CPU components are clocked according to the CPU clock rate. For a MinorCPU model (defined in the commands we use to run the benchmarks), these components are:

1. L1 data cache (dcache)
2. L1 instruction cache (icache)
3. L2 cache
4. Instruction walker cache
5. Data walker cache
6. Data busses that connect the components mentioned above

If we add another CPU, meaning we add another core to the CPU cluster, its clock rate will be the defined CPU clock rate, always according to its architecture.

For the scaling we have the following execution times for the 1GHz and 3GHz simulations:

Simulation time (in seconds)
| | 401.bzip2 | 429.mcf | 456.hmmer | 458.sjeng | 470.lbm | 
| --- | --- | --- | --- | -- | --- |
| 1GHz | 0.165228 | 0.124137 | 0.118530 | 0.329087 | 0.246976 |
| 3GHz | 0.061589 | 0.043909 | 0.039646 | 0.138401 | 0.135953 |

As we can observe from the table, in some cases the scaling is better than the others (specifically, in benchmark 456.hmmer we can see that the rate is closer to 3 than in 470.lbm). Achieving perfect scaling is close to impossible, because the system performance depends on a lot of parameters other than CPU clock (for example: cache line size).

### Bibliography

1. [http://pages.cs.wisc.edu/~david/courses/cs752/Fall2015/gem5-tutorial/index.html](http://pages.cs.wisc.edu/~david/courses/cs752/Fall2015/gem5-tutorial/index.html)
2. [https://www.gem5.org/documentation/](https://www.gem5.org/documentation/)
