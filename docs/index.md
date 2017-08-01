---
layout: default
---

# [](#header-1)Beckground Story

Many people agree that cat is a cute animal. Look at this picture.


Despite the cuteness, not everybody feels comfortable with blue color. Some people prefur green, as depicted in the following picture.



This project demonstrates how to use OpenCV to help us enjoying the cuteness of a cat while maintaining our favorite color

# [](#header-1)How the code works

## [](#header-2)Formula

Let's take a simple example of grayscale image. Given a grayscale image with intensity 0-255, we want to convert all pixels with intensity 50-100 to 125-150. Simple math will allows us to do it. Let's formulate:

```octave
initial-intensity-min: 50

initial intensity-max: 100

target-intensity-min: 125

target-intensity-max: 150
```

The new image can be obtained started with masking the image to obtain the region of interest (we remove all the pixels with intensity outside 50-100 range). Let's denote this as Masked Image. Then we process the image as the following:

```octave
Processed Image = target-intensity-min + ((Masked Image - initial-intensity-min) / (initial-intensity-max - initial-intensity-min)) * (target-intensity-max - target-intensity-min)
```

The final image can be obtained by combining by adding the Processed Image with the pixels outside the region of interest.

---

---

## [](#header-2)Explanation



# [](#header-1)Usage 

## [](#header-2)Grayscale

## [](#header-2)HSV Color Image

Text can be **bold**, _italic_, or ~~strikethrough~~.

[Link to another page](another-page).

There should be whitespace between paragraphs.
There should be whitespace between paragraphs. We recommend including a README, or a file with information about your project.

# [](#header-1)Header 1
This is a normal paragraph following a header. GitHub is a code hosting platform for version control and collaboration. It lets you and others work together on projects from anywhere.

## [](#header-2)Header 2

> This is a blockquote following a header.
>
> When something is important enough, you do it even if the odds are not in your favor.

### [](#header-3)Header 

```js
// Javascript code with syntax highlighting.
var fun = function lang(l) {
  dateformat.i18n = require('./lang/' + l)
  return true;
}
```

```ruby
# Ruby code with syntax highlighting
GitHubPages::Dependencies.gems.each do |gem, version|
  s.add_dependency(gem, "= #{version}")
end
```

#### [](#header-4)Header 4

*   This is an unordered list following a header.
*   This is an unordered list following a header.
*   This is an unordered list following a header.

##### [](#header-5)Header 5

1.  This is an ordered list following a header.
2.  This is an ordered list following a header.
3.  This is an ordered list following a header.

###### [](#header-6)Header 6

| head1        | head two          | three |
|:-------------|:------------------|:------|
| ok           | good swedish fish | nice  |
| out of stock | good and plenty   | nice  |
| ok           | good `oreos`      | hmm   |
| ok           | good `zoute` drop | yumm  |

### There's a horizontal rule below this.

* * *

### Here is an unordered list:

*   Item foo
*   Item bar
*   Item baz
*   Item zip

### And an ordered list:

1.  Item one
1.  Item two
1.  Item three
1.  Item four

### And a nested list:

- level 1 item
  - level 2 item
  - level 2 item
    - level 3 item
    - level 3 item
- level 1 item
  - level 2 item
  - level 2 item
  - level 2 item
- level 1 item
  - level 2 item
  - level 2 item
- level 1 item

### Small image

![](https://assets-cdn.github.com/images/icons/emoji/octocat.png)

### Large image

![](https://guides.github.com/activities/hello-world/branching.png)


### Definition lists can be used with HTML syntax.

<dl>
<dt>Name</dt>
<dd>Godzilla</dd>
<dt>Born</dt>
<dd>1952</dd>
<dt>Birthplace</dt>
<dd>Japan</dd>
<dt>Color</dt>
<dd>Green</dd>
</dl>

```
Long, single-line code blocks should not wrap. They should horizontally scroll if they are too long. This line should be long enough to demonstrate this.
```

```
The final element.
```
