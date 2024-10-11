# France-IOI Solutions

Accepted solutions of [France-IOI problemset](https://www.france-ioi.org/algo/chapters.php).

## Table of Contents

{% for level, chapters in levels.items() %}
- [{{ level }}](#{{ level | lower | replace(' ', '-') }})
{% for chapter, problems in chapters.items() %} 
    - [{{ chapter }}](#{{ chapter | lower | replace(' ', '-') }})
{% endfor %}
{% endfor %}

---

{% for level, chapters in levels.items() %}

## {{ level }}

{% for chapter, content in chapters.items() %}

### {{ chapter }}

{% for problem in content.problems %}
1. <a href="{{ level | replace(' ', '%20') }}/{{ chapter | replace(' ', '%20') }}/{{ problem.title | replace(' ', '%20') }}.{{ problem.extension }}"> 💻 {{ problem.title }} </a>
{% endfor %}

{% for part in content.parts %}

1. **{{ part.part }}**

{% for subproblem in part.problems %}
    1. <a href="{{ level | replace(' ', '%20') }}/{{ chapter | replace(' ', '%20') }}/{{ part.part | replace(' ', '%20') }}/{{ subproblem.title | replace(' ', '%20') }}.{{ subproblem.extension }}"> 💻 {{ subproblem.title }} </a>
{% endfor %}

{% endfor %}
{% endfor %}
{% endfor %}
