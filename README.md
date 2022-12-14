# This repo serves as the report and codebase for Lab 1/3 for the Advanced Computer Architecture course, on the Electrical and Computer Engineering school of Aristotle University of Thessaloniki

Ανδρονίκου Δημήτρης, 9836

Αλεξανδρίδης Φώτιος, 9953

---
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

 - AtomicSimpleCPUs: they have no pipeline, and are therefore completely unrealistic. However, they do run much faster. They execute all processes of an instruction in one clock cycle. Memory access is done directly and they use Atomic memory accesses.
  
 - TimingSimpleCPUs: They have no pipeline, and are therefore completely unrealistic. However, they run much faster. They use Timing memory accesses which means they wait until the memory access is complete. Memory access requests take time to reach the memory system and return. But because there is no CPU pipeline, the simulated CPU idles on each memory request waiting for a response.
 
 - MinorCPUs: Minor is used to model processors with strict in-order execution behavior and allows visualization of an instruction's position in the pipeline through the MinorTrace tool. It provides a framework for associating the model with a specific, selected processor with similar capabilities. It is considered more realistic than previous models, but is not currently capable of multithreading. It is a model with a fixed pipeline but with configurable data structures and execution behavior.
 
It has four pipeline stages:
1. fetch1
2. fetch2
3. decode
4. execute

- High-Performance In-orderCPUs (HPI): The HPI timing model is tuned to be representative of a modern Armv8-A in-order implementation. The HPI pipeline uses the same four-stage model as the MinorCPU 

A Generic Interrupt Controller (GIC) supports the routing of software-generated, private and shared peripheral interrupts between. The GIC allows software to hide, enable and disable interrupts, from individual sources, to prioritize (hardware) individual sources, and to generate software interrupts.

The Data Processing Unit(Data Processing Unit-DPU) contains general purpose registers and system registers. This allows the memory system to be configured and controlled and to decode and execute instructions. The FPU contains the floating-point registers and status registers. It performs floating-point operations on the data in the floating-point register file. The DPU and FPU can be modeled by the functional units (FU) in the Execute stage of the MinorCPU pipeline.

It also has an L1 instruction cache and an L1 data cache. 

The Memory Management Unit (MMU) is to allow the system to execute multiple tasks as independent programs running in their own private virtual memory space. They do not need any knowledge of the physical memory mapping of the system, i.e. the addresses actually used by the hardware.

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


In general, the hardest part of this assignment was the toolchain setup. After that was done, the next obstacle was the large size of the output files(for the hello world example the `config.ini` file has 1537 lines, and the `stats.txt` file has 1181 lines), and as such parsing them and retrieving the requested information was time consuming. Finally, the example benchmark program should benchmark more aspects of memory, and as such a guideline for that would be useful (e.g. a program
that stores a large amount of data in memory, or that reads different memory locations frequently, thus interacting frequently with cache), in order for this first lab to not be too time consuming, since the focus of this lab is to set up an environment, familiarize ourselves with the tools we are going to use, and develop a robust testing/simulating setup (automate cross compilation, execution with parametrizable bash/python scripts). The gem5 documentation is really helpful and
detailed to the extent needed (provides the user with sensible defaults and bite-sized portions of information when starting out). 

### Bibliography

1. [http://pages.cs.wisc.edu/~david/courses/cs752/Fall2015/gem5-tutorial/index.html](http://pages.cs.wisc.edu/~david/courses/cs752/Fall2015/gem5-tutorial/index.html)
2. [https://www.gem5.org/documentation/](https://www.gem5.org/documentation/)
