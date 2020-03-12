function submit () {
    var ans = [];
    
	if(document.getElementById('n1').checked == true){
        ans.push('김구');
    }
    if(document.getElementById('n2').checked == true){
        ans.push('안창호');
    }
    if(document.getElementById('n3').checked == true){
        ans.push('손병희');
    }
    if(document.getElementById('n4').checked == true){
        ans.push('양기탁');
    }
    if(document.getElementById('n5').checked == true){
        ans.push('안중근');
    }

	
	fetch('/submit', {
		method: 'POST',
		headers: {'Content-Type': 'application/json'},
		body: JSON.stringify({answers:ans})
	})
		.then(res => res.json())
		.then(ret => {
			// Update Element
			if(ret == true){
				document.getElementById('result').innerHTML = '정답입니다.';
			}
			else{
				document.getElementById('result').innerHTML = '오답입니다.';
			}
		});
};
