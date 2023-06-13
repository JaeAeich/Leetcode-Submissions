type F = (x: number) => number;

function compose(functions: F[]): F {
	return function(x) {
        this.val = x;
        for(let i = functions.length-1;i>=0;i--){
            this.val = functions[i](this.val);
        }
        return this.val;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */