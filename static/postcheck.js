var cTries=0
function onSubmit(obj)
{
	var x=document.postform
	if (x.subject.value.length == 0) {
		alert("��������, ����������, ���-������ � ������� �� ����������� ����� ������ ���������! �������!");
		return false;
	}
	if (x.subject.value.length > 65530) {
		alert("������ ������ ��������� ��������� �������� ��");
		return false;
	}
	if(obj)x.jpost.value = obj.name;
		if(document.all||document.getElementById) {
			for(i = 0; i < x.length; i++) {
				var tempobj = x.elements[i]
				if( tempobj.type && 
					(tempobj.type.toLowerCase() == "submit" || tempobj.type.toLowerCase() == "reset"))
					tempobj.disabled=true
		}
	}
	
	if(cTries++ == 0)
	x.submit();
	return false;
}	
