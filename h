
    ref 
        https://github.com/deveshks/locking-schemes-evaluation/blob/master/Main.java

    high lev understanding 
        gen 
            stack can easily be lock-free, but not queue, why? -xxx
            use cas to solve n consensus problem？ -png in answer  -xxx
        goal? 
            we want [effciently] [correctly] accessing to [shared resource or shared structured resource] 
        detail?the book? 
            **[PartI]theory
                our imp. should be correct, and effcient.
                Linearizability... 
                improve capability of registers
                Consensus Numbers to masure atomic instructions
                ...
            **[PartII]practice 
                we want effciently accessing to shared resource or structured resource 
                维度1：effciently[partII of the book]
                    with lock
                        software solution:
                            Peterson's lock(algorithm),Queue Locks,Hierarchical Locks...(advanced locks)
                            (codes in book uses only ReentrantLock())
                        hardware: lock,mutex...
                    without lock 
                        optimistic... method 
                        hardware solution:TAS:Test-and-set instruction,getAndIncrement()....
                维度2:shared resource
                    simple structured(initial)
                        SRSW,MRSW,MRMW....we can 
                    complex structured resource(more useful)[partII of the book]
                        list,stack,queue....
                example:
                    wait-free linked list
                    Fine-Grained Locking linked list 
                    wait-free queue 
                    Fine-Grained Locking hashmap
                    ...
        codes to write: 
            ...
            -ext
        how to achieve lock-free/ wait-free? 
            lock-free
                *CAS opera.
                retry 
                construct
                ...
            wait-free
                1.limit steps -xxx
                    help 
                    fast-path-slow-path methodology
                    encapsule         
                    mark     
                    decide...
                    throw ?? may not work
                        actually, there sth called CAS spin-loops...
                        then every thing becomes wait-free  
                    **not usual to use CAS operations, useually use CAS with loop, thus can cause contention 
                    **no cas waitfree introduced in book and slide
                2.construct
        judge if it is wait-free?  -xxx
            1.lock? 
            2.while(true),retry?
            ...
        illu.all! x9 large algo!!/ fields? func.?    --optimized concurrent objs pdf i wrote -xxx
            draw the class!:https://online.visual-paradigm.com/images/features/uml-tool/02-class-diagram-example-car.png
                linked-list
                    nsm-diff. method has diff. progress guarantee
                    ok
                queue
                    1.helping pending scheme...
                    2.fast-path-slow-path methodology
                    3.with FAA::with CAS huge contention, other read-modify-write primitives?
                        https://dl.acm.org/citation.cfm?doid=2851141.2851168
                    ///
                stack
                    similar to queue 
                    ///
                hashing 
                    nsm-diff. method has diff. progress guarantee
                    ok
                snapshot    
                    easily waitfree, without cas 
                    ok
                universal
                    ok  

                barrier 
                    other thing 
                    ok
                skip list 
                    lock-free??
                    The basis of our LockFreeSkipList implementation is the LockFreeList
                        algorithm of Chapter 9: each level of the SkipList structure is a LockFreeList,
                        each next reference in a node is an AtomicMarkableReference<Node>, and
                        list manipulations are performed using compareAndSet()
                    ///
                counting  
                    other 
                    ok 
            ..
                -execp69 
            +
                每一个方法详细实现！！！！！
        *for particular application: competition!!
            prime counting  -xxx
                1.data para. -not balanced 
                2.shared counter -has contention
                s::combining trees? 
                    lower contention, but lock-free only? ...
                s::wait-free queue? 
                    load 1-10^10 to a queue, then concurrently deq()
                    ok but not practical
                s::CAS lock-free 
            mandelbrot
                s::balanced? shared counter? lock free queue? CAS
            hemino benchmark
                s::CBT barrier --> static tree barrier 
        where to go? 
            queue, stack, skiplist!(db)
             
