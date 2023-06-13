function createCounter(n: number): () => number {
    this.prev = n;
    
    return function() {
        return this.prev++;
    }
}


/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */