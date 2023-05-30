/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    let cnt=0,index=0;
    return new Promise((resolve)=>{
        const FiveStar=()=>{
            while(cnt<n&&index<functions.length){
                cnt++;
                const promise=functions[index]();
                index++;
                promise.then(()=>{
                    cnt-=1;
                    FiveStar();
                })
            }
            if(cnt==0&&index==functions.length){
                resolve();
                return;
            }
        }
        FiveStar();
    })
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */