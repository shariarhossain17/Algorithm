function onlyPositive(numbers) {
    if (!Array.isArray(numbers)) {
        return 'Please give me an array of some numbers'
    }

    let positiveNumber = [];
    for (let i = 0; i < numbers.length; i++){
        const arrayNumbers = numbers[i]
        if (typeof arrayNumbers !== 'number') {
            return 'Please give me some numbers';
        } 

        if(arrayNumbers > 0){
            positiveNumber.push(arrayNumbers);
        }
        else{
            break;
        }
    }

    return positiveNumber;
}   
    const myArr = [45, 87, 96, 11, 63, -56, 71, 28]
    console.log(onlyPositive(myArr));