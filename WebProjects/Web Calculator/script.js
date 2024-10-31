let display = '';
let input = document.querySelectorAll('.button');
Array.from(input).forEach((button) => {
    button.addEventListener('click', (f) => {
    


        if (f.target.innerHTML == '+' || f.target.innerHTML == '-' || f.target.innerHTML == '*' || f.target.innerHTML == '/') {
            display += '\n';
        }

        if (f.target.innerHTML == '=') {
            display = eval(display);
            document.querySelector('textarea').value = display;
        }

        else if (f.target.innerHTML == 'C') {
            display = '';
            document.querySelector('textarea').value = display;

        }

        else {
            console.log(f.target);
            display += f.target.innerHTML;
            document.querySelector('textarea').value = display;
        }

        let text = document.getElementById('display');
        text.scrollTop = text.scrollHeight;

        let result = '';
        if (display == '') { }
        else {
            result += '=';
            result += eval(display);
        }
        document.querySelector('input').value = result;

    })
});