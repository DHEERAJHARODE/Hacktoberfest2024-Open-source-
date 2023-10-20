let boldCheckbox = document.getElementById('bold');
let italicCheckbox = document.getElementById('italic');
let underlineCheckbox = document.getElementById('underline');
let fontSelect = document.getElementById('font');
let colorInput = document.getElementById('color');
let sizeSelect = document.getElementById('size');
let caseSelect = document.getElementById('case');
let contentRadios = document.querySelectorAll('input[name="content"]');
// let alignRadios = document.querySelectorAll('input[name="align"]');
let clearButton = document.querySelector('.button.clear');
let textboxes = document.querySelectorAll("input[type='text']");
let selectedTextbox = null
let main = document.querySelector(".main")
let paras = main.querySelectorAll("p")

textboxes.forEach(textbox => {
    textbox.addEventListener('click', () => {
        selectedTextbox = textbox;
    });

    boldCheckbox.addEventListener('change', () => {
        textbox.style.fontWeight = boldCheckbox.checked ? 'bold' : 'normal';
    });

    italicCheckbox.addEventListener('change', () => {
        textbox.style.fontStyle = italicCheckbox.checked ? 'italic' : 'normal';
    });

    underlineCheckbox.addEventListener('change', () => {
        textbox.style.textDecoration = underlineCheckbox.checked ? 'underline' : 'none';
    });

    fontSelect.addEventListener('change', () => {
        if (fontSelect.value === 'space-mono') {
            textbox.style.fontFamily = "Space Mono";
        } else if (fontSelect.value === 'libre-bodoni') {
            textbox.style.fontFamily = "Libre Bodoni";
        } else {
            textbox.style.fontFamily = "Josefin Sans";
        }
    });

    colorInput.addEventListener('input', () => {
        textbox.style.color = colorInput.value;
    });

    sizeSelect.addEventListener('change', () => {
            textbox.style.fontSize = sizeSelect.value + 'px';
            paras.forEach(para => {
                para.style.fontSize = sizeSelect.value + 'px';
            })
    });

    caseSelect.addEventListener('change', () => {
        let selectedCase = caseSelect.value;
        if (selectedCase === 'capitalize') {
            textbox.style.textTransform = 'capitalize';
        } else if (selectedCase === 'upper') {
            textbox.style.textTransform = 'uppercase';
        } else if (selectedCase === 'lower') {
            textbox.style.textTransform = 'lowercase';
        }
    });

    contentRadios.forEach(radio => {
        radio.addEventListener('change', () => {
            textbox.style.textAlign = radio.value;
        });
    });

    // alignRadios.forEach(alRadio => {
    //     alRadio.addEventListener('change', () => {
    //         if (selectedTextbox) {
    //             selectedTextbox.style.display = 'flex'
    //             selectedTextbox.style.alignItems = alRadio.value;
    //         }
    //     });
    // });
})

clearButton.addEventListener('click', () => {
    for (let i = 1; i <= 1300; i++) {
        var textboxes = document.querySelectorAll("input[type='text']");
        textboxes.forEach(function(textbox) {
            textbox.value = "";
        });
    }
});