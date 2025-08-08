├── .gitignore
├── LICENSE
├── README.md
├── examples
    └── Basic
    │   └── Basic.ino
├── keywords.txt
├── library.json
├── library.properties
└── src
    ├── ArDebugger.h
    ├── EspFileManager.cpp
    ├── EspFileManager.h
    └── webPage.h


/.gitignore:
--------------------------------------------------------------------------------
1 | /dashboard
2 | /src/page.h
3 | 


--------------------------------------------------------------------------------
/LICENSE:
--------------------------------------------------------------------------------
  1 |                     GNU AFFERO GENERAL PUBLIC LICENSE
  2 |                        Version 3, 19 November 2007
  3 | 
  4 |  Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
  5 |  Everyone is permitted to copy and distribute verbatim copies
  6 |  of this license document, but changing it is not allowed.
  7 | 
  8 |                             Preamble
  9 | 
 10 |   The GNU Affero General Public License is a free, copyleft license for
 11 | software and other kinds of works, specifically designed to ensure
 12 | cooperation with the community in the case of network server software.
 13 | 
 14 |   The licenses for most software and other practical works are designed
 15 | to take away your freedom to share and change the works.  By contrast,
 16 | our General Public Licenses are intended to guarantee your freedom to
 17 | share and change all versions of a program--to make sure it remains free
 18 | software for all its users.
 19 | 
 20 |   When we speak of free software, we are referring to freedom, not
 21 | price.  Our General Public Licenses are designed to make sure that you
 22 | have the freedom to distribute copies of free software (and charge for
 23 | them if you wish), that you receive source code or can get it if you
 24 | want it, that you can change the software or use pieces of it in new
 25 | free programs, and that you know you can do these things.
 26 | 
 27 |   Developers that use our General Public Licenses protect your rights
 28 | with two steps: (1) assert copyright on the software, and (2) offer
 29 | you this License which gives you legal permission to copy, distribute
 30 | and/or modify the software.
 31 | 
 32 |   A secondary benefit of defending all users' freedom is that
 33 | improvements made in alternate versions of the program, if they
 34 | receive widespread use, become available for other developers to
 35 | incorporate.  Many developers of free software are heartened and
 36 | encouraged by the resulting cooperation.  However, in the case of
 37 | software used on network servers, this result may fail to come about.
 38 | The GNU General Public License permits making a modified version and
 39 | letting the public access it on a server without ever releasing its
 40 | source code to the public.
 41 | 
 42 |   The GNU Affero General Public License is designed specifically to
 43 | ensure that, in such cases, the modified source code becomes available
 44 | to the community.  It requires the operator of a network server to
 45 | provide the source code of the modified version running there to the
 46 | users of that server.  Therefore, public use of a modified version, on
 47 | a publicly accessible server, gives the public access to the source
 48 | code of the modified version.
 49 | 
 50 |   An older license, called the Affero General Public License and
 51 | published by Affero, was designed to accomplish similar goals.  This is
 52 | a different license, not a version of the Affero GPL, but Affero has
 53 | released a new version of the Affero GPL which permits relicensing under
 54 | this license.
 55 | 
 56 |   The precise terms and conditions for copying, distribution and
 57 | modification follow.
 58 | 
 59 |                        TERMS AND CONDITIONS
 60 | 
 61 |   0. Definitions.
 62 | 
 63 |   "This License" refers to version 3 of the GNU Affero General Public License.
 64 | 
 65 |   "Copyright" also means copyright-like laws that apply to other kinds of
 66 | works, such as semiconductor masks.
 67 | 
 68 |   "The Program" refers to any copyrightable work licensed under this
 69 | License.  Each licensee is addressed as "you".  "Licensees" and
 70 | "recipients" may be individuals or organizations.
 71 | 
 72 |   To "modify" a work means to copy from or adapt all or part of the work
 73 | in a fashion requiring copyright permission, other than the making of an
 74 | exact copy.  The resulting work is called a "modified version" of the
 75 | earlier work or a work "based on" the earlier work.
 76 | 
 77 |   A "covered work" means either the unmodified Program or a work based
 78 | on the Program.
 79 | 
 80 |   To "propagate" a work means to do anything with it that, without
 81 | permission, would make you directly or secondarily liable for
 82 | infringement under applicable copyright law, except executing it on a
 83 | computer or modifying a private copy.  Propagation includes copying,
 84 | distribution (with or without modification), making available to the
 85 | public, and in some countries other activities as well.
 86 | 
 87 |   To "convey" a work means any kind of propagation that enables other
 88 | parties to make or receive copies.  Mere interaction with a user through
 89 | a computer network, with no transfer of a copy, is not conveying.
 90 | 
 91 |   An interactive user interface displays "Appropriate Legal Notices"
 92 | to the extent that it includes a convenient and prominently visible
 93 | feature that (1) displays an appropriate copyright notice, and (2)
 94 | tells the user that there is no warranty for the work (except to the
 95 | extent that warranties are provided), that licensees may convey the
 96 | work under this License, and how to view a copy of this License.  If
 97 | the interface presents a list of user commands or options, such as a
 98 | menu, a prominent item in the list meets this criterion.
 99 | 
100 |   1. Source Code.
101 | 
102 |   The "source code" for a work means the preferred form of the work
103 | for making modifications to it.  "Object code" means any non-source
104 | form of a work.
105 | 
106 |   A "Standard Interface" means an interface that either is an official
107 | standard defined by a recognized standards body, or, in the case of
108 | interfaces specified for a particular programming language, one that
109 | is widely used among developers working in that language.
110 | 
111 |   The "System Libraries" of an executable work include anything, other
112 | than the work as a whole, that (a) is included in the normal form of
113 | packaging a Major Component, but which is not part of that Major
114 | Component, and (b) serves only to enable use of the work with that
115 | Major Component, or to implement a Standard Interface for which an
116 | implementation is available to the public in source code form.  A
117 | "Major Component", in this context, means a major essential component
118 | (kernel, window system, and so on) of the specific operating system
119 | (if any) on which the executable work runs, or a compiler used to
120 | produce the work, or an object code interpreter used to run it.
121 | 
122 |   The "Corresponding Source" for a work in object code form means all
123 | the source code needed to generate, install, and (for an executable
124 | work) run the object code and to modify the work, including scripts to
125 | control those activities.  However, it does not include the work's
126 | System Libraries, or general-purpose tools or generally available free
127 | programs which are used unmodified in performing those activities but
128 | which are not part of the work.  For example, Corresponding Source
129 | includes interface definition files associated with source files for
130 | the work, and the source code for shared libraries and dynamically
131 | linked subprograms that the work is specifically designed to require,
132 | such as by intimate data communication or control flow between those
133 | subprograms and other parts of the work.
134 | 
135 |   The Corresponding Source need not include anything that users
136 | can regenerate automatically from other parts of the Corresponding
137 | Source.
138 | 
139 |   The Corresponding Source for a work in source code form is that
140 | same work.
141 | 
142 |   2. Basic Permissions.
143 | 
144 |   All rights granted under this License are granted for the term of
145 | copyright on the Program, and are irrevocable provided the stated
146 | conditions are met.  This License explicitly affirms your unlimited
147 | permission to run the unmodified Program.  The output from running a
148 | covered work is covered by this License only if the output, given its
149 | content, constitutes a covered work.  This License acknowledges your
150 | rights of fair use or other equivalent, as provided by copyright law.
151 | 
152 |   You may make, run and propagate covered works that you do not
153 | convey, without conditions so long as your license otherwise remains
154 | in force.  You may convey covered works to others for the sole purpose
155 | of having them make modifications exclusively for you, or provide you
156 | with facilities for running those works, provided that you comply with
157 | the terms of this License in conveying all material for which you do
158 | not control copyright.  Those thus making or running the covered works
159 | for you must do so exclusively on your behalf, under your direction
160 | and control, on terms that prohibit them from making any copies of
161 | your copyrighted material outside their relationship with you.
162 | 
163 |   Conveying under any other circumstances is permitted solely under
164 | the conditions stated below.  Sublicensing is not allowed; section 10
165 | makes it unnecessary.
166 | 
167 |   3. Protecting Users' Legal Rights From Anti-Circumvention Law.
168 | 
169 |   No covered work shall be deemed part of an effective technological
170 | measure under any applicable law fulfilling obligations under article
171 | 11 of the WIPO copyright treaty adopted on 20 December 1996, or
172 | similar laws prohibiting or restricting circumvention of such
173 | measures.
174 | 
175 |   When you convey a covered work, you waive any legal power to forbid
176 | circumvention of technological measures to the extent such circumvention
177 | is effected by exercising rights under this License with respect to
178 | the covered work, and you disclaim any intention to limit operation or
179 | modification of the work as a means of enforcing, against the work's
180 | users, your or third parties' legal rights to forbid circumvention of
181 | technological measures.
182 | 
183 |   4. Conveying Verbatim Copies.
184 | 
185 |   You may convey verbatim copies of the Program's source code as you
186 | receive it, in any medium, provided that you conspicuously and
187 | appropriately publish on each copy an appropriate copyright notice;
188 | keep intact all notices stating that this License and any
189 | non-permissive terms added in accord with section 7 apply to the code;
190 | keep intact all notices of the absence of any warranty; and give all
191 | recipients a copy of this License along with the Program.
192 | 
193 |   You may charge any price or no price for each copy that you convey,
194 | and you may offer support or warranty protection for a fee.
195 | 
196 |   5. Conveying Modified Source Versions.
197 | 
198 |   You may convey a work based on the Program, or the modifications to
199 | produce it from the Program, in the form of source code under the
200 | terms of section 4, provided that you also meet all of these conditions:
201 | 
202 |     a) The work must carry prominent notices stating that you modified
203 |     it, and giving a relevant date.
204 | 
205 |     b) The work must carry prominent notices stating that it is
206 |     released under this License and any conditions added under section
207 |     7.  This requirement modifies the requirement in section 4 to
208 |     "keep intact all notices".
209 | 
210 |     c) You must license the entire work, as a whole, under this
211 |     License to anyone who comes into possession of a copy.  This
212 |     License will therefore apply, along with any applicable section 7
213 |     additional terms, to the whole of the work, and all its parts,
214 |     regardless of how they are packaged.  This License gives no
215 |     permission to license the work in any other way, but it does not
216 |     invalidate such permission if you have separately received it.
217 | 
218 |     d) If the work has interactive user interfaces, each must display
219 |     Appropriate Legal Notices; however, if the Program has interactive
220 |     interfaces that do not display Appropriate Legal Notices, your
221 |     work need not make them do so.
222 | 
223 |   A compilation of a covered work with other separate and independent
224 | works, which are not by their nature extensions of the covered work,
225 | and which are not combined with it such as to form a larger program,
226 | in or on a volume of a storage or distribution medium, is called an
227 | "aggregate" if the compilation and its resulting copyright are not
228 | used to limit the access or legal rights of the compilation's users
229 | beyond what the individual works permit.  Inclusion of a covered work
230 | in an aggregate does not cause this License to apply to the other
231 | parts of the aggregate.
232 | 
233 |   6. Conveying Non-Source Forms.
234 | 
235 |   You may convey a covered work in object code form under the terms
236 | of sections 4 and 5, provided that you also convey the
237 | machine-readable Corresponding Source under the terms of this License,
238 | in one of these ways:
239 | 
240 |     a) Convey the object code in, or embodied in, a physical product
241 |     (including a physical distribution medium), accompanied by the
242 |     Corresponding Source fixed on a durable physical medium
243 |     customarily used for software interchange.
244 | 
245 |     b) Convey the object code in, or embodied in, a physical product
246 |     (including a physical distribution medium), accompanied by a
247 |     written offer, valid for at least three years and valid for as
248 |     long as you offer spare parts or customer support for that product
249 |     model, to give anyone who possesses the object code either (1) a
250 |     copy of the Corresponding Source for all the software in the
251 |     product that is covered by this License, on a durable physical
252 |     medium customarily used for software interchange, for a price no
253 |     more than your reasonable cost of physically performing this
254 |     conveying of source, or (2) access to copy the
255 |     Corresponding Source from a network server at no charge.
256 | 
257 |     c) Convey individual copies of the object code with a copy of the
258 |     written offer to provide the Corresponding Source.  This
259 |     alternative is allowed only occasionally and noncommercially, and
260 |     only if you received the object code with such an offer, in accord
261 |     with subsection 6b.
262 | 
263 |     d) Convey the object code by offering access from a designated
264 |     place (gratis or for a charge), and offer equivalent access to the
265 |     Corresponding Source in the same way through the same place at no
266 |     further charge.  You need not require recipients to copy the
267 |     Corresponding Source along with the object code.  If the place to
268 |     copy the object code is a network server, the Corresponding Source
269 |     may be on a different server (operated by you or a third party)
270 |     that supports equivalent copying facilities, provided you maintain
271 |     clear directions next to the object code saying where to find the
272 |     Corresponding Source.  Regardless of what server hosts the
273 |     Corresponding Source, you remain obligated to ensure that it is
274 |     available for as long as needed to satisfy these requirements.
275 | 
276 |     e) Convey the object code using peer-to-peer transmission, provided
277 |     you inform other peers where the object code and Corresponding
278 |     Source of the work are being offered to the general public at no
279 |     charge under subsection 6d.
280 | 
281 |   A separable portion of the object code, whose source code is excluded
282 | from the Corresponding Source as a System Library, need not be
283 | included in conveying the object code work.
284 | 
285 |   A "User Product" is either (1) a "consumer product", which means any
286 | tangible personal property which is normally used for personal, family,
287 | or household purposes, or (2) anything designed or sold for incorporation
288 | into a dwelling.  In determining whether a product is a consumer product,
289 | doubtful cases shall be resolved in favor of coverage.  For a particular
290 | product received by a particular user, "normally used" refers to a
291 | typical or common use of that class of product, regardless of the status
292 | of the particular user or of the way in which the particular user
293 | actually uses, or expects or is expected to use, the product.  A product
294 | is a consumer product regardless of whether the product has substantial
295 | commercial, industrial or non-consumer uses, unless such uses represent
296 | the only significant mode of use of the product.
297 | 
298 |   "Installation Information" for a User Product means any methods,
299 | procedures, authorization keys, or other information required to install
300 | and execute modified versions of a covered work in that User Product from
301 | a modified version of its Corresponding Source.  The information must
302 | suffice to ensure that the continued functioning of the modified object
303 | code is in no case prevented or interfered with solely because
304 | modification has been made.
305 | 
306 |   If you convey an object code work under this section in, or with, or
307 | specifically for use in, a User Product, and the conveying occurs as
308 | part of a transaction in which the right of possession and use of the
309 | User Product is transferred to the recipient in perpetuity or for a
310 | fixed term (regardless of how the transaction is characterized), the
311 | Corresponding Source conveyed under this section must be accompanied
312 | by the Installation Information.  But this requirement does not apply
313 | if neither you nor any third party retains the ability to install
314 | modified object code on the User Product (for example, the work has
315 | been installed in ROM).
316 | 
317 |   The requirement to provide Installation Information does not include a
318 | requirement to continue to provide support service, warranty, or updates
319 | for a work that has been modified or installed by the recipient, or for
320 | the User Product in which it has been modified or installed.  Access to a
321 | network may be denied when the modification itself materially and
322 | adversely affects the operation of the network or violates the rules and
323 | protocols for communication across the network.
324 | 
325 |   Corresponding Source conveyed, and Installation Information provided,
326 | in accord with this section must be in a format that is publicly
327 | documented (and with an implementation available to the public in
328 | source code form), and must require no special password or key for
329 | unpacking, reading or copying.
330 | 
331 |   7. Additional Terms.
332 | 
333 |   "Additional permissions" are terms that supplement the terms of this
334 | License by making exceptions from one or more of its conditions.
335 | Additional permissions that are applicable to the entire Program shall
336 | be treated as though they were included in this License, to the extent
337 | that they are valid under applicable law.  If additional permissions
338 | apply only to part of the Program, that part may be used separately
339 | under those permissions, but the entire Program remains governed by
340 | this License without regard to the additional permissions.
341 | 
342 |   When you convey a copy of a covered work, you may at your option
343 | remove any additional permissions from that copy, or from any part of
344 | it.  (Additional permissions may be written to require their own
345 | removal in certain cases when you modify the work.)  You may place
346 | additional permissions on material, added by you to a covered work,
347 | for which you have or can give appropriate copyright permission.
348 | 
349 |   Notwithstanding any other provision of this License, for material you
350 | add to a covered work, you may (if authorized by the copyright holders of
351 | that material) supplement the terms of this License with terms:
352 | 
353 |     a) Disclaiming warranty or limiting liability differently from the
354 |     terms of sections 15 and 16 of this License; or
355 | 
356 |     b) Requiring preservation of specified reasonable legal notices or
357 |     author attributions in that material or in the Appropriate Legal
358 |     Notices displayed by works containing it; or
359 | 
360 |     c) Prohibiting misrepresentation of the origin of that material, or
361 |     requiring that modified versions of such material be marked in
362 |     reasonable ways as different from the original version; or
363 | 
364 |     d) Limiting the use for publicity purposes of names of licensors or
365 |     authors of the material; or
366 | 
367 |     e) Declining to grant rights under trademark law for use of some
368 |     trade names, trademarks, or service marks; or
369 | 
370 |     f) Requiring indemnification of licensors and authors of that
371 |     material by anyone who conveys the material (or modified versions of
372 |     it) with contractual assumptions of liability to the recipient, for
373 |     any liability that these contractual assumptions directly impose on
374 |     those licensors and authors.
375 | 
376 |   All other non-permissive additional terms are considered "further
377 | restrictions" within the meaning of section 10.  If the Program as you
378 | received it, or any part of it, contains a notice stating that it is
379 | governed by this License along with a term that is a further
380 | restriction, you may remove that term.  If a license document contains
381 | a further restriction but permits relicensing or conveying under this
382 | License, you may add to a covered work material governed by the terms
383 | of that license document, provided that the further restriction does
384 | not survive such relicensing or conveying.
385 | 
386 |   If you add terms to a covered work in accord with this section, you
387 | must place, in the relevant source files, a statement of the
388 | additional terms that apply to those files, or a notice indicating
389 | where to find the applicable terms.
390 | 
391 |   Additional terms, permissive or non-permissive, may be stated in the
392 | form of a separately written license, or stated as exceptions;
393 | the above requirements apply either way.
394 | 
395 |   8. Termination.
396 | 
397 |   You may not propagate or modify a covered work except as expressly
398 | provided under this License.  Any attempt otherwise to propagate or
399 | modify it is void, and will automatically terminate your rights under
400 | this License (including any patent licenses granted under the third
401 | paragraph of section 11).
402 | 
403 |   However, if you cease all violation of this License, then your
404 | license from a particular copyright holder is reinstated (a)
405 | provisionally, unless and until the copyright holder explicitly and
406 | finally terminates your license, and (b) permanently, if the copyright
407 | holder fails to notify you of the violation by some reasonable means
408 | prior to 60 days after the cessation.
409 | 
410 |   Moreover, your license from a particular copyright holder is
411 | reinstated permanently if the copyright holder notifies you of the
412 | violation by some reasonable means, this is the first time you have
413 | received notice of violation of this License (for any work) from that
414 | copyright holder, and you cure the violation prior to 30 days after
415 | your receipt of the notice.
416 | 
417 |   Termination of your rights under this section does not terminate the
418 | licenses of parties who have received copies or rights from you under
419 | this License.  If your rights have been terminated and not permanently
420 | reinstated, you do not qualify to receive new licenses for the same
421 | material under section 10.
422 | 
423 |   9. Acceptance Not Required for Having Copies.
424 | 
425 |   You are not required to accept this License in order to receive or
426 | run a copy of the Program.  Ancillary propagation of a covered work
427 | occurring solely as a consequence of using peer-to-peer transmission
428 | to receive a copy likewise does not require acceptance.  However,
429 | nothing other than this License grants you permission to propagate or
430 | modify any covered work.  These actions infringe copyright if you do
431 | not accept this License.  Therefore, by modifying or propagating a
432 | covered work, you indicate your acceptance of this License to do so.
433 | 
434 |   10. Automatic Licensing of Downstream Recipients.
435 | 
436 |   Each time you convey a covered work, the recipient automatically
437 | receives a license from the original licensors, to run, modify and
438 | propagate that work, subject to this License.  You are not responsible
439 | for enforcing compliance by third parties with this License.
440 | 
441 |   An "entity transaction" is a transaction transferring control of an
442 | organization, or substantially all assets of one, or subdividing an
443 | organization, or merging organizations.  If propagation of a covered
444 | work results from an entity transaction, each party to that
445 | transaction who receives a copy of the work also receives whatever
446 | licenses to the work the party's predecessor in interest had or could
447 | give under the previous paragraph, plus a right to possession of the
448 | Corresponding Source of the work from the predecessor in interest, if
449 | the predecessor has it or can get it with reasonable efforts.
450 | 
451 |   You may not impose any further restrictions on the exercise of the
452 | rights granted or affirmed under this License.  For example, you may
453 | not impose a license fee, royalty, or other charge for exercise of
454 | rights granted under this License, and you may not initiate litigation
455 | (including a cross-claim or counterclaim in a lawsuit) alleging that
456 | any patent claim is infringed by making, using, selling, offering for
457 | sale, or importing the Program or any portion of it.
458 | 
459 |   11. Patents.
460 | 
461 |   A "contributor" is a copyright holder who authorizes use under this
462 | License of the Program or a work on which the Program is based.  The
463 | work thus licensed is called the contributor's "contributor version".
464 | 
465 |   A contributor's "essential patent claims" are all patent claims
466 | owned or controlled by the contributor, whether already acquired or
467 | hereafter acquired, that would be infringed by some manner, permitted
468 | by this License, of making, using, or selling its contributor version,
469 | but do not include claims that would be infringed only as a
470 | consequence of further modification of the contributor version.  For
471 | purposes of this definition, "control" includes the right to grant
472 | patent sublicenses in a manner consistent with the requirements of
473 | this License.
474 | 
475 |   Each contributor grants you a non-exclusive, worldwide, royalty-free
476 | patent license under the contributor's essential patent claims, to
477 | make, use, sell, offer for sale, import and otherwise run, modify and
478 | propagate the contents of its contributor version.
479 | 
480 |   In the following three paragraphs, a "patent license" is any express
481 | agreement or commitment, however denominated, not to enforce a patent
482 | (such as an express permission to practice a patent or covenant not to
483 | sue for patent infringement).  To "grant" such a patent license to a
484 | party means to make such an agreement or commitment not to enforce a
485 | patent against the party.
486 | 
487 |   If you convey a covered work, knowingly relying on a patent license,
488 | and the Corresponding Source of the work is not available for anyone
489 | to copy, free of charge and under the terms of this License, through a
490 | publicly available network server or other readily accessible means,
491 | then you must either (1) cause the Corresponding Source to be so
492 | available, or (2) arrange to deprive yourself of the benefit of the
493 | patent license for this particular work, or (3) arrange, in a manner
494 | consistent with the requirements of this License, to extend the patent
495 | license to downstream recipients.  "Knowingly relying" means you have
496 | actual knowledge that, but for the patent license, your conveying the
497 | covered work in a country, or your recipient's use of the covered work
498 | in a country, would infringe one or more identifiable patents in that
499 | country that you have reason to believe are valid.
500 | 
501 |   If, pursuant to or in connection with a single transaction or
502 | arrangement, you convey, or propagate by procuring conveyance of, a
503 | covered work, and grant a patent license to some of the parties
504 | receiving the covered work authorizing them to use, propagate, modify
505 | or convey a specific copy of the covered work, then the patent license
506 | you grant is automatically extended to all recipients of the covered
507 | work and works based on it.
508 | 
509 |   A patent license is "discriminatory" if it does not include within
510 | the scope of its coverage, prohibits the exercise of, or is
511 | conditioned on the non-exercise of one or more of the rights that are
512 | specifically granted under this License.  You may not convey a covered
513 | work if you are a party to an arrangement with a third party that is
514 | in the business of distributing software, under which you make payment
515 | to the third party based on the extent of your activity of conveying
516 | the work, and under which the third party grants, to any of the
517 | parties who would receive the covered work from you, a discriminatory
518 | patent license (a) in connection with copies of the covered work
519 | conveyed by you (or copies made from those copies), or (b) primarily
520 | for and in connection with specific products or compilations that
521 | contain the covered work, unless you entered into that arrangement,
522 | or that patent license was granted, prior to 28 March 2007.
523 | 
524 |   Nothing in this License shall be construed as excluding or limiting
525 | any implied license or other defenses to infringement that may
526 | otherwise be available to you under applicable patent law.
527 | 
528 |   12. No Surrender of Others' Freedom.
529 | 
530 |   If conditions are imposed on you (whether by court order, agreement or
531 | otherwise) that contradict the conditions of this License, they do not
532 | excuse you from the conditions of this License.  If you cannot convey a
533 | covered work so as to satisfy simultaneously your obligations under this
534 | License and any other pertinent obligations, then as a consequence you may
535 | not convey it at all.  For example, if you agree to terms that obligate you
536 | to collect a royalty for further conveying from those to whom you convey
537 | the Program, the only way you could satisfy both those terms and this
538 | License would be to refrain entirely from conveying the Program.
539 | 
540 |   13. Remote Network Interaction; Use with the GNU General Public License.
541 | 
542 |   Notwithstanding any other provision of this License, if you modify the
543 | Program, your modified version must prominently offer all users
544 | interacting with it remotely through a computer network (if your version
545 | supports such interaction) an opportunity to receive the Corresponding
546 | Source of your version by providing access to the Corresponding Source
547 | from a network server at no charge, through some standard or customary
548 | means of facilitating copying of software.  This Corresponding Source
549 | shall include the Corresponding Source for any work covered by version 3
550 | of the GNU General Public License that is incorporated pursuant to the
551 | following paragraph.
552 | 
553 |   Notwithstanding any other provision of this License, you have
554 | permission to link or combine any covered work with a work licensed
555 | under version 3 of the GNU General Public License into a single
556 | combined work, and to convey the resulting work.  The terms of this
557 | License will continue to apply to the part which is the covered work,
558 | but the work with which it is combined will remain governed by version
559 | 3 of the GNU General Public License.
560 | 
561 |   14. Revised Versions of this License.
562 | 
563 |   The Free Software Foundation may publish revised and/or new versions of
564 | the GNU Affero General Public License from time to time.  Such new versions
565 | will be similar in spirit to the present version, but may differ in detail to
566 | address new problems or concerns.
567 | 
568 |   Each version is given a distinguishing version number.  If the
569 | Program specifies that a certain numbered version of the GNU Affero General
570 | Public License "or any later version" applies to it, you have the
571 | option of following the terms and conditions either of that numbered
572 | version or of any later version published by the Free Software
573 | Foundation.  If the Program does not specify a version number of the
574 | GNU Affero General Public License, you may choose any version ever published
575 | by the Free Software Foundation.
576 | 
577 |   If the Program specifies that a proxy can decide which future
578 | versions of the GNU Affero General Public License can be used, that proxy's
579 | public statement of acceptance of a version permanently authorizes you
580 | to choose that version for the Program.
581 | 
582 |   Later license versions may give you additional or different
583 | permissions.  However, no additional obligations are imposed on any
584 | author or copyright holder as a result of your choosing to follow a
585 | later version.
586 | 
587 |   15. Disclaimer of Warranty.
588 | 
589 |   THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
590 | APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
591 | HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY
592 | OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,
593 | THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
594 | PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM
595 | IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF
596 | ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
597 | 
598 |   16. Limitation of Liability.
599 | 
600 |   IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
601 | WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS
602 | THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY
603 | GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE
604 | USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF
605 | DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD
606 | PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS),
607 | EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF
608 | SUCH DAMAGES.
609 | 
610 |   17. Interpretation of Sections 15 and 16.
611 | 
612 |   If the disclaimer of warranty and limitation of liability provided
613 | above cannot be given local legal effect according to their terms,
614 | reviewing courts shall apply local law that most closely approximates
615 | an absolute waiver of all civil liability in connection with the
616 | Program, unless a warranty or assumption of liability accompanies a
617 | copy of the Program in return for a fee.
618 | 
619 |                      END OF TERMS AND CONDITIONS
620 | 
621 |             How to Apply These Terms to Your New Programs
622 | 
623 |   If you develop a new program, and you want it to be of the greatest
624 | possible use to the public, the best way to achieve this is to make it
625 | free software which everyone can redistribute and change under these terms.
626 | 
627 |   To do so, attach the following notices to the program.  It is safest
628 | to attach them to the start of each source file to most effectively
629 | state the exclusion of warranty; and each file should have at least
630 | the "copyright" line and a pointer to where the full notice is found.
631 | 
632 |     <one line to give the program's name and a brief idea of what it does.>
633 |     Copyright (C) <year>  <name of author>
634 | 
635 |     This program is free software: you can redistribute it and/or modify
636 |     it under the terms of the GNU Affero General Public License as published
637 |     by the Free Software Foundation, either version 3 of the License, or
638 |     (at your option) any later version.
639 | 
640 |     This program is distributed in the hope that it will be useful,
641 |     but WITHOUT ANY WARRANTY; without even the implied warranty of
642 |     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
643 |     GNU Affero General Public License for more details.
644 | 
645 |     You should have received a copy of the GNU Affero General Public License
646 |     along with this program.  If not, see <https://www.gnu.org/licenses/>.
647 | 
648 | Also add information on how to contact you by electronic and paper mail.
649 | 
650 |   If your software can interact with users remotely through a computer
651 | network, you should also make sure that it provides a way for users to
652 | get its source.  For example, if your program is a web application, its
653 | interface could display a "Source" link that leads users to an archive
654 | of the code.  There are many ways you could offer source, and different
655 | solutions will be better for different programs; see section 13 for the
656 | specific requirements.
657 | 
658 |   You should also get your employer (if you work as a programmer) or school,
659 | if any, to sign a "copyright disclaimer" for the program, if necessary.
660 | For more information on this, and how to apply and follow the GNU AGPL, see
661 | <https://www.gnu.org/licenses/>.
662 | 


--------------------------------------------------------------------------------
/README.md:
--------------------------------------------------------------------------------
 1 | # EspFileManager
 2 | 
 3 | **EspFileManager** is a library for creating a web-based file management system on the ESP32 using the Async WebServer library. The library provides a responsive interface that allows users to upload, download, and delete files stored on the ESP32's filesystem.
 4 | 
 5 | ## Features
 6 | - **File Management:** Upload, download, and delete files via a web interface.
 7 | - **Responsive Design:** Interface adapts to different screen sizes, providing a smooth experience on desktops, tablets, and smartphones.
 8 | 
 9 | ## Installation
10 | 
11 | ### Arduino IDE
12 | 1. Navigate to the library manager (Sketch > Include Library > Manage Libraries).
13 | 2. Search for "EspFileManager" and install it.
14 | 
15 | ### PlatformIO
16 | 1. Add the library to your `platformio.ini`:
17 |    ```ini
18 |    lib_deps =
19 |        https://github.com/arslan437/EspFileManager.git
20 | 
21 | ## Usage
22 | 
23 |     ```cpp
24 |     #include <AsyncTCP.h>
25 |     #include <ESPAsyncWebServer.h>
26 |     #include <SPI.h>
27 |     #include <SD.h>
28 |     #include <WiFi.h>
29 | 
30 | 
31 |     #include <EspFileManager.h>
32 | 
33 |     #define MICROSD_SPI_SS_PIN 5
34 |     #define ST_SSID "XXXXXXXXXXX"
35 |     #define ST_PASS "XXXXXXXXXXX"
36 | 
37 |     AsyncWebServer server(80);
38 |     EspFileManager FileManager;
39 | 
40 |     void setup() 
41 |     {
42 |         Serial.begin(115200);
43 | 
44 |         WiFi.mode(WIFI_STA);
45 |         WiFi.begin(ST_SSID, ST_PASS);
46 |         while (WiFi.status() != WL_CONNECTED);
47 |         {
48 |             Serial.print(".");
49 |             delay(50);
50 |         }
51 |         Serial.print("Connected to wifi... \nIP: ");
52 |         Serial.println(WiFi.localIP());
53 | 
54 |         FileManager.initSDCard(&SD, MICROSD_SPI_SS_PIN);
55 |         FileManager.setServer(&server);
56 | 
57 |         server.begin();
58 |     }
59 | 
60 |     void loop() 
61 |     {
62 |     
63 |     }
64 | 
65 | ## Support
66 | 
67 | Creating meaningful content is my passion, but it’s also a labor of love that requires time, energy, and often a bit of coffee to keep the creativity flowing! By buying me a cup of coffee, you're not just fueling my caffeine habit—you're helping me continue to create, innovate, and bring fresh ideas to life. Your support means the world to me, and every contribution, big or small, makes a huge difference.
68 | 
69 | ## Contributing
70 | 
71 | Contributions are welcome! Please feel free to submit a Pull Request on GitHub.
72 | 
73 | ## License
74 | 
75 | This library is licensed under the AGPL-3.0 License. See LICENSE for more information.


--------------------------------------------------------------------------------
/examples/Basic/Basic.ino:
--------------------------------------------------------------------------------
 1 | #include <AsyncTCP.h>
 2 | #include <ESPAsyncWebServer.h>
 3 | #include <SPI.h>
 4 | #include <SD.h>
 5 | #include <WiFi.h>
 6 | 
 7 | 
 8 | #include <EspFileManager.h>
 9 | 
10 | #define MICROSD_SPI_SS_PIN 5
11 | #define ST_SSID "XXXXXXXXXXX"
12 | #define ST_PASS "XXXXXXXXXXX"
13 | 
14 | AsyncWebServer server(80);
15 | EspFileManager FileManager;
16 | 
17 | void setup() 
18 | {
19 |   Serial.begin(115200);
20 | 
21 |   WiFi.mode(WIFI_STA);
22 | 	WiFi.begin(ST_SSID, ST_PASS);
23 | 	while (WiFi.status() != WL_CONNECTED);
24 | 	{
25 | 		Serial.print(".");
26 | 		delay(50);
27 | 	}
28 |   Serial.print("Connected to wifi... \nIP: ");
29 |   Serial.println(WiFi.localIP());
30 | 
31 |   FileManager.initSDCard(&SD, MICROSD_SPI_SS_PIN);
32 |   FileManager.setServer(&server);
33 | 
34 |   server.begin();
35 | }
36 | 
37 | void loop() 
38 | {
39 |   
40 | }


--------------------------------------------------------------------------------
/keywords.txt:
--------------------------------------------------------------------------------
1 | esp32-file-manager    KEYWORD1
2 | webserver             KEYWORD2
3 | file                  KEYWORD3
4 | manager               KEYWORD4
5 | 


--------------------------------------------------------------------------------
/library.json:
--------------------------------------------------------------------------------
 1 | {
 2 |     "name": "EspFileManager",
 3 |     "version": "1.0.2",
 4 |     "description": "Web-based file manager for ESP32 file operations.",
 5 |     "keywords": ["ESP32", "WebServer", "File Manager", "EspFileManager"],
 6 |     "repository": {
 7 |       "type": "git",
 8 |       "url": "https://github.com/arslan437/EspFileManager.git"
 9 |     },
10 |     "authors": [
11 |       {
12 |         "name": "Muhammad Arslan",
13 |         "email": "email@example.com",
14 |         "maintainer": true
15 |       }
16 |     ],
17 |     "frameworks": "arduino",
18 |     "platforms": "espressif32",
19 |     "export": {
20 |       "exclude": [
21 |         "dashboard",           
22 |         "src/page.h"    
23 |       ]
24 |     }
25 |   }
26 |   


--------------------------------------------------------------------------------
/library.properties:
--------------------------------------------------------------------------------
 1 | name=EspFileManager
 2 | version=1.0.2
 3 | author=Muhammad Arslan
 4 | maintainer=Muhammad Arslan
 5 | sentence=Web-based file manager for ESP32 file operations.
 6 | paragraph=This library provides a web interface for managing files on an ESP32, supporting uploads, downloads, and deletions.
 7 | category=Communication
 8 | url=https://github.com/arslan437/EspFileManager.git
 9 | architectures=esp32
10 | repository=https://github.com/arslan437/EspFileManager.git
11 | license=AGPL-3.0 
12 | 


--------------------------------------------------------------------------------
/src/ArDebugger.h:
--------------------------------------------------------------------------------
 1 | #ifndef AR_DEBUGGER_H
 2 | #define AR_DEBUGGER_H
 3 | 
 4 | #include <Arduino.h>
 5 | 
 6 | // #define DEBUG_SERIAL Serial
 7 | // #define EN_DEBUG
 8 | 
 9 | /*
10 | *   For debuging.
11 | */
12 | 
13 | #ifdef EN_DEBUG
14 | 
15 | /*
16 |  * With New Line
17 |  */
18 | #define DEBUGL(x)       DEBUG_SERIAL.println(x)
19 | #define DEBUGLF(x)      DEBUG_SERIAL.println(F(x))
20 | #define DEBUGL2(x, y)   DEBUG_SERIAL.print(F(x)); DEBUG_SERIAL.println(y)
21 | #define DEBUGLP(x, y)   DEBUG_SERIAL.println(x, y)
22 | 
23 | /*
24 |  * Without New Line
25 |  */
26 | #define DEBUGX(...)     DEBUG_SERIAL.printf(__VA_ARGS__)
27 | #define DEBUG(x)        DEBUG_SERIAL.print(x)
28 | #define DEBUGF(x)       DEBUG_SERIAL.print(F(x))
29 | #define DEBUGP(x, y)    DEBUG_SERIAL.print(x, y)
30 | 
31 | #else
32 | 
33 | /*
34 |  * With New Line
35 |  */
36 | #define DEBUGL(x)       while(false)
37 | #define DEBUGLF(x)      while(false)
38 | #define DEBUGL2(x, y)   while(false)
39 | #define DEBUGLP(x, y)   while(false)
40 | 
41 | /*
42 |  * Without New Line
43 |  */
44 | #define DEBUGX(...)     while(false)
45 | #define DEBUG(x)        while(false)
46 | #define DEBUGF(x)       while(false)
47 | #define DEBUGP(x, y)    while(false)
48 | 
49 | #endif
50 | 
51 | #endif


--------------------------------------------------------------------------------
/src/EspFileManager.cpp:
--------------------------------------------------------------------------------
  1 | #include "EspFileManager.h"
  2 | // #include "page.h"
  3 | #include "webPage.h"
  4 | #include "FS.h"
  5 | #include <SD.h>
  6 | #include "SPI.h"
  7 | 
  8 | 
  9 | EspFileManager::EspFileManager(/* args */)
 10 | {
 11 | 
 12 | }
 13 | 
 14 | EspFileManager::~EspFileManager()
 15 | {
 16 | }
 17 | 
 18 | 
 19 | bool EspFileManager::initSDCard(fs::SDFS *storage, uint8_t _cs)
 20 | {
 21 |     sd_cs = _cs;
 22 |     _storage = storage;
 23 | 
 24 |     if (!_storage->begin(sd_cs))
 25 |     // if (!_storage->begin())
 26 |     {
 27 |         DEBUGLF("Card Mount Failed");
 28 |         memory_ready = false;
 29 |         return false;
 30 |     }
 31 | 
 32 |     uint8_t cardType = _storage->cardType();
 33 | 
 34 |     if (cardType == CARD_NONE)
 35 |     {
 36 |         DEBUGLF("No SD card attached");
 37 |         memory_ready = false;
 38 |         return false;
 39 |     }
 40 | 
 41 |     memory_ready = true;
 42 |     DEBUGF("SD Card Type: ");
 43 |     if (cardType == CARD_MMC)
 44 |     {
 45 |         DEBUGLF("MMC");
 46 |     }
 47 |     else if (cardType == CARD_SD)
 48 |     {
 49 |         DEBUGLF("SDSC");
 50 |     }
 51 |     else if (cardType == CARD_SDHC)
 52 |     {
 53 |         DEBUGLF("SDHC");
 54 |     }
 55 |     else
 56 |     {
 57 |         DEBUGLF("UNKNOWN");
 58 |     }
 59 | 
 60 |     if(memory_ready)
 61 |     {
 62 |         // uint32_t cardSize = _storage->cardSize() / (1024 * 1024);
 63 |         // DEBUGX("SD Card Size: %lluMB\n", cardSize);
 64 |         // DEBUGL2("SD Card Size: ", cardSize);
 65 |     }
 66 |     return false;
 67 | }
 68 | 
 69 | void EspFileManager::setFileSource(fs::SDFS *storage)
 70 | {   
 71 |     _storage = storage;
 72 | }
 73 | 
 74 | void EspFileManager::listDir(const char * dirname, uint8_t levels)
 75 | {
 76 |     DEBUGX("Listing directory: %s\n", dirname);
 77 | 
 78 |     File root = _storage->open(dirname);
 79 |     if(!root){
 80 |         DEBUGLF("Failed to open directory");
 81 |         return;
 82 |     }
 83 |     if(!root.isDirectory()){
 84 |         DEBUGLF("Not a directory");
 85 |         return;
 86 |     }
 87 | 
 88 |     bool first_files = true;
 89 |     str_data = "";
 90 |     File file = root.openNextFile();
 91 |     while(file){
 92 |         if (first_files)
 93 |             first_files = false;
 94 |         else 
 95 |             str_data += ":";
 96 | 
 97 |         if(file.isDirectory()){
 98 |             // DEBUGF("  DIR : ");
 99 |             // DEBUGL(file.name());
100 |             str_data += "1,";
101 |             str_data += file.name();
102 |             // if(levels){
103 |             //     listDir(file.path(), levels -1);
104 |             // }
105 |         } else {
106 |             // DEBUG("  FILE: ");
107 |             // DEBUG(file.name());
108 |             // DEBUG("  SIZE: ");
109 |             // DEBUGL(file.size());
110 |             str_data += "0,";
111 |             str_data += file.name();
112 |         }
113 |         file = root.openNextFile();
114 |     }
115 | 
116 |     file.close();
117 |     // DEBUGL2("Folder string ", str_data);
118 | }
119 | 
120 | void EspFileManager::setServer(AsyncWebServer *server)
121 | {
122 |     if (server == nullptr) {
123 |         DEBUGLF("Server is null!");
124 |         return;
125 |     }
126 |     _server = server;
127 | 
128 |     _server->on("/file", HTTP_GET, [&](AsyncWebServerRequest *request){ 
129 |             AsyncWebServerResponse *response = request->beginResponse_P(200, "text/html", html_page, html_page_len);
130 |             response->addHeader("Content-Encoding", "gzip");
131 |             request->send(response);
132 |             // request->send(200, "text/html", html_page); 
133 |             // request->send(200, "text/plain", "Test route working");
134 |         });
135 | 
136 |     server->on("/get-folder-contents", HTTP_GET, [&](AsyncWebServerRequest *request){
137 |         DEBUGL2("path:", request->arg("path").c_str());
138 |         listDir(request->arg("path").c_str(), 0);
139 |         request->send(200, "text/plain", str_data);
140 |     });
141 | 
142 |     server->on("/upload", HTTP_POST, [&](AsyncWebServerRequest *request)
143 |         { request->send(200, "application/json", "{\"status\":\"success\",\"message\":\"File upload complete\"}"); }, [&](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final){
144 |         String file_path;
145 | 
146 |         file_path = "/";
147 |         file_path += filename;
148 | 
149 |         if(!index)
150 |         {
151 |             DEBUGX("UploadStart: %s\n", file_path.c_str());
152 |             if(_storage->exists(file_path)) 
153 |             {
154 |                 _storage->remove(file_path);
155 |             }
156 |         }
157 | 
158 |         File file = _storage->open(file_path, FILE_APPEND);
159 |         if(file) 
160 |         {
161 |             if(file.write(data, len) != len)
162 |             {
163 |                 DEBUGLF("File write failed");
164 |             }
165 |             file.close();
166 |         }
167 |         if(final)
168 |         {
169 |             DEBUGX("UploadEnd: %s, %u B\n", file_path.c_str(), index+len);
170 |         } 
171 |     });
172 | 
173 |     server->on("/delete", HTTP_GET, [&](AsyncWebServerRequest *request){
174 |         String path;
175 |         if (request->hasParam("path")) 
176 |         {
177 |             path = request->getParam("path")->value();
178 |         } 
179 |         else 
180 |         {
181 |             request->send(400, "application/json", "{\"status\":\"error\",\"message\":\"Path not provided\"}");
182 |             return;
183 |         }
184 | 
185 |         DEBUGL2("Deleting File: ", path);
186 |         if (_storage->exists(path)) 
187 |         {
188 |             _storage->remove(path);
189 |             request->send(200, "application/json", "{\"status\":\"success\",\"message\":\"File deleted successfully\"}");
190 |         } 
191 |         else 
192 |         {
193 |             request->send(404, "application/json", "{\"status\":\"error\",\"message\":\"File not found\"}");
194 |         } 
195 |     });
196 | 
197 |     server->on("/download", HTTP_GET, [&](AsyncWebServerRequest *request){
198 |         String path;
199 |         if (request->hasParam("path")) 
200 |         {
201 |             path = request->getParam("path")->value();
202 |         } 
203 |         else 
204 |         {
205 |             request->send(400, "application/json", "{\"status\":\"error\",\"message\":\"Path not provided\"}");
206 |             return;
207 |         }
208 |         DEBUGL2("Downloading File: ", path);
209 |         if (_storage->exists(path)) 
210 |         {
211 |             request->send(*_storage, path, String(), true);
212 |         } 
213 |         else 
214 |         {
215 |             request->send(404, "application/json", "{\"status\":\"error\",\"message\":\"File not found\"}");
216 |         } 
217 |     });
218 | }
219 | 


--------------------------------------------------------------------------------
/src/EspFileManager.h:
--------------------------------------------------------------------------------
 1 | #pragma once 
 2 | 
 3 | /*
 4 |  * Auther: Muhammad Arslan
 5 |  * Dated: 15-08-2024
 6 |  * Discription: This library provides an easy way to manage the files on the flash/sd card using webpage.
 7 |  */
 8 | 
 9 | #include <Arduino.h>
10 | #include <SD.h>
11 | 
12 | #ifdef ESP32
13 | #include <AsyncTCP.h>
14 | #elif defined(ESP8266)
15 | #include <ESPAsyncTCP.h>
16 | #endif
17 | #include <ESPAsyncWebServer.h>
18 | 
19 | // #define EN_DEBUG
20 | #define DEBUG_SERIAL Serial
21 | #include <ArDebugger.h>
22 | 
23 | #define LIBRARY_VERSION "1.0.0"
24 | 
25 | class EspFileManager
26 | {
27 | private:
28 |     uint8_t sd_cs, sd_sck, sd_miso, sd_mosi;
29 |     bool memory_ready = false;
30 |     String str_data = "";
31 |     fs::SDFS *_storage;
32 |     AsyncWebServer *_server;
33 | public:
34 |     EspFileManager(/* args */);
35 |     ~EspFileManager();
36 | 
37 |     // void begin(AsyncWebServer *server, FS *fs);
38 | 
39 |     bool initSDCard(SDFS *storage, uint8_t _cs);
40 |     void setFileSource(SDFS *storage);
41 |     void listDir(const char * dirname, uint8_t levels);
42 | 
43 |     void setServer(AsyncWebServer *server);
44 | };
45 | 
46 | 


--------------------------------------------------------------------------------
/src/webPage.h:
--------------------------------------------------------------------------------
  1 | #ifndef WEBPAGE_H
  2 | #define WEBPAGE_H
  3 | 
  4 | const size_t html_page_len = 2493;
  5 | const uint8_t html_page[] = {
  6 |     0x1f, 0x8b, 0x08, 0x00, 0x65, 0x73, 0x03, 0x67, 0x02, 0xff, 0xe5, 0x5a, 
  7 |     0xfd, 0x8e, 0xdb, 0xc6, 0x11, 0xff, 0xbf, 0x40, 0xdf, 0x61, 0x2d, 0xdb, 
  8 |     0x20, 0x65, 0x1c, 0x29, 0x9d, 0x3f, 0xd0, 0x44, 0x3e, 0x5d, 0x10, 0x9f, 
  9 |     0xcf, 0x8d, 0x01, 0xbb, 0x31, 0x9a, 0x0b, 0xd0, 0xc2, 0x30, 0x70, 0x2b, 
 10 |     0x72, 0x29, 0x6d, 0x4c, 0x91, 0x0c, 0xb9, 0xbc, 0x8f, 0x18, 0xfa, 0xa3, 
 11 |     0x40, 0xdf, 0xa0, 0x0f, 0xd0, 0x57, 0xec, 0x23, 0x74, 0x66, 0x49, 0x8a, 
 12 |     0xcb, 0xe5, 0x2e, 0xa9, 0xb3, 0x1d, 0xa0, 0x40, 0xcf, 0xb1, 0x4f, 0xe2, 
 13 |     0xce, 0xce, 0xce, 0xfc, 0xe6, 0x7b, 0x99, 0x93, 0x7b, 0x2f, 0x7f, 0x3c, 
 14 |     0xbb, 0xf8, 0xfb, 0xbb, 0x73, 0xb2, 0x11, 0xdb, 0xf8, 0xf4, 0x8f, 0x7f, 
 15 |     0x38, 0xc1, 0xdf, 0x24, 0xa6, 0xc9, 0x7a, 0x39, 0x61, 0xc9, 0x04, 0x9e, 
 16 |     0xe0, 0x33, 0x46, 0x43, 0xf8, 0x44, 0xe0, 0xe7, 0x64, 0xcb, 0x04, 0x25, 
 17 |     0xc1, 0x86, 0xe6, 0x05, 0x13, 0xcb, 0xc9, 0xcf, 0x17, 0xaf, 0xbc, 0x6f, 
 18 |     0x26, 0x9d, 0xb5, 0x84, 0x6e, 0xd9, 0x72, 0x72, 0xc5, 0xd9, 0x75, 0x96, 
 19 |     0xe6, 0x62, 0x42, 0x82, 0x34, 0x11, 0x2c, 0x01, 0xda, 0x6b, 0x1e, 0x8a, 
 20 |     0xcd, 0x32, 0x64, 0x57, 0x3c, 0x60, 0x9e, 0xfc, 0x72, 0x44, 0x78, 0xc2, 
 21 |     0x05, 0xa7, 0xb1, 0x57, 0x04, 0x34, 0x66, 0xcb, 0x63, 0x7f, 0xbe, 0xe7, 
 22 |     0x25, 0xb8, 0x88, 0xd9, 0xe9, 0x2b, 0x1e, 0x33, 0xf2, 0x96, 0x26, 0x74, 
 23 |     0xcd, 0xf2, 0x93, 0x59, 0xf5, 0xac, 0x26, 0x28, 0xc4, 0xed, 0xfe, 0x0b, 
 24 |     0xfe, 0xcc, 0x1e, 0x91, 0x17, 0xb4, 0xe0, 0x01, 0xc1, 0x05, 0x9e, 0xac, 
 25 |     0xc9, 0xa3, 0x59, 0xbb, 0xb8, 0x4a, 0xc3, 0x5b, 0xf2, 0xa9, 0xfd, 0x8e, 
 26 |     0x3f, 0x11, 0x08, 0xe6, 0x45, 0x74, 0xcb, 0xe3, 0xdb, 0x05, 0xf9, 0x3e, 
 27 |     0x07, 0x31, 0x8e, 0x48, 0x41, 0x93, 0xc2, 0x2b, 0x58, 0xce, 0xa3, 0xe7, 
 28 |     0x5d, 0xe2, 0x15, 0x0d, 0x3e, 0xae, 0xf3, 0xb4, 0x4c, 0x42, 0x2f, 0x48, 
 29 |     0xe3, 0x34, 0x5f, 0x90, 0xfb, 0xd1, 0x1c, 0xff, 0x68, 0x74, 0xcd, 0xe2, 
 30 |     0x93, 0x27, 0x4f, 0xb4, 0x95, 0x2d, 0xcd, 0xd7, 0x3c, 0x59, 0x10, 0x7d, 
 31 |     0x47, 0x46, 0xc3, 0x10, 0xc4, 0xed, 0x2e, 0xec, 0x10, 0xf7, 0xe6, 0x8b, 
 32 |     0x8f, 0xf8, 0xb3, 0x5c, 0x97, 0xdf, 0x24, 0x92, 0xfc, 0xb1, 0x1d, 0x70, 
 33 |     0x3c, 0xcf, 0x6e, 0xb4, 0xb5, 0x90, 0x17, 0x59, 0x4c, 0x41, 0xff, 0x28, 
 34 |     0x66, 0xfa, 0xda, 0x2f, 0x65, 0x21, 0x78, 0x74, 0xeb, 0xd5, 0x06, 0x5c, 
 35 |     0x90, 0x22, 0xa3, 0x60, 0xb9, 0x15, 0x13, 0xd7, 0x8c, 0x25, 0x1a, 0x31, 
 36 |     0x8d, 0xf9, 0x3a, 0xf1, 0xb8, 0x60, 0xdb, 0x62, 0x41, 0x02, 0x20, 0x67, 
 37 |     0xb9, 0x8e, 0x60, 0x7a, 0xe3, 0x15, 0x1b, 0x1a, 0xa6, 0xd7, 0xa0, 0x2a, 
 38 |     0x79, 0x9c, 0xdd, 0x90, 0xa7, 0xf0, 0x37, 0x5f, 0xaf, 0xa8, 0x3b, 0x3f, 
 39 |     0x22, 0xf5, 0x7f, 0xfe, 0xf1, 0xd4, 0x86, 0xc2, 0xe6, 0x58, 0x07, 0xc0, 
 40 |     0x86, 0xa8, 0x34, 0x6c, 0xc1, 0x7f, 0x63, 0x0b, 0xf2, 0xf8, 0x69, 0x4f, 
 41 |     0xe5, 0x06, 0xab, 0xf9, 0xfc, 0x4f, 0x34, 0x08, 0xac, 0x98, 0x6f, 0x59, 
 42 |     0x52, 0x7a, 0x2b, 0xda, 0x43, 0x7d, 0x08, 0xb1, 0x35, 0xcd, 0x7a, 0x28, 
 43 |     0x5b, 0xb8, 0xae, 0x4a, 0x21, 0xd2, 0x44, 0x67, 0xde, 0x31, 0x15, 0x79, 
 44 |     0xdc, 0xb7, 0x97, 0xc1, 0xe6, 0x3d, 0x3d, 0x2a, 0xb0, 0x73, 0xf0, 0x98, 
 45 |     0x05, 0x49, 0xd2, 0x84, 0x19, 0x97, 0xbc, 0x9c, 0x86, 0xbc, 0x04, 0x5b, 
 46 |     0x3d, 0xb3, 0x02, 0x64, 0x74, 0xa6, 0xa0, 0xcc, 0x0b, 0x5c, 0xcd, 0x52, 
 47 |     0x6e, 0xb0, 0xb1, 0x82, 0xfc, 0xf1, 0xd3, 0xc3, 0x61, 0x58, 0x6c, 0xd2, 
 48 |     0xab, 0x83, 0xfc, 0x7b, 0x3e, 0x7f, 0x16, 0x7d, 0xfb, 0xad, 0x95, 0x2d, 
 49 |     0x7a, 0x2a, 0xe5, 0x49, 0x9f, 0xd5, 0x1e, 0x57, 0x03, 0xa4, 0x5b, 0x7a, 
 50 |     0x53, 0x65, 0x23, 0x44, 0x7d, 0x6e, 0x5a, 0xaf, 0xbd, 0x8c, 0xd0, 0x52, 
 51 |     0xa4, 0xb6, 0xb3, 0xef, 0xa3, 0xb4, 0xde, 0xff, 0x9b, 0x55, 0x5b, 0x7c, 
 52 |     0xbc, 0x55, 0x0a, 0xaa, 0x6f, 0x87, 0xdd, 0x5f, 0x05, 0xe9, 0x6b, 0xd9, 
 53 |     0x3c, 0x82, 0x0a, 0xe1, 0x6d, 0xab, 0x0a, 0x71, 0x97, 0x58, 0xc5, 0x47, 
 54 |     0x5e, 0xc8, 0x73, 0x16, 0x08, 0x0e, 0xd2, 0x20, 0x3e, 0xe5, 0x36, 0x39, 
 55 |     0x20, 0xa0, 0x15, 0x9d, 0x45, 0x9a, 0xf5, 0x5c, 0xaa, 0x2b, 0x1d, 0x26, 
 56 |     0xc4, 0xbb, 0x48, 0xd5, 0xcb, 0xb9, 0x52, 0xcc, 0x42, 0xd0, 0x5c, 0xdc, 
 57 |     0x39, 0xe1, 0x0e, 0xe5, 0xfd, 0x43, 0x6b, 0xc7, 0xa8, 0x5b, 0x7d, 0x69, 
 58 |     0x56, 0xf7, 0x79, 0xd0, 0x0f, 0x98, 0x1a, 0xde, 0x9c, 0xaf, 0x37, 0x62, 
 59 |     0x24, 0xa1, 0x52, 0x69, 0xbe, 0xc2, 0xc2, 0x21, 0x66, 0x11, 0x30, 0x18, 
 60 |     0x8a, 0xdb, 0x3d, 0x83, 0x91, 0xd0, 0x05, 0xcd, 0x0f, 0xc4, 0xf1, 0x7f, 
 61 |     0x35, 0x72, 0x1f, 0xdb, 0xbc, 0xb8, 0x02, 0xe9, 0xd9, 0x01, 0x20, 0x7f, 
 62 |     0xdd, 0xc8, 0x2d, 0xb3, 0x38, 0xa5, 0xa1, 0xb7, 0x4d, 0x43, 0x1a, 0x5b, 
 63 |     0x63, 0xc4, 0x00, 0x58, 0x96, 0x16, 0xbc, 0x8a, 0xd9, 0x88, 0xdf, 0xb0, 
 64 |     0x50, 0x5b, 0x95, 0x31, 0xf9, 0x6c, 0xfe, 0x50, 0x7b, 0x5c, 0x2b, 0xd9, 
 65 |     0x7b, 0x2e, 0x72, 0xe8, 0xf8, 0xa2, 0x34, 0x87, 0xcc, 0x25, 0x3f, 0xc6, 
 66 |     0x54, 0x30, 0xd7, 0x03, 0xba, 0x23, 0x82, 0xff, 0x4e, 0xc7, 0xed, 0xfd, 
 67 |     0x84, 0xe2, 0x9f, 0xe7, 0x87, 0x17, 0x1c, 0xcd, 0xe0, 0x26, 0xaf, 0x3a, 
 68 |     0x28, 0xa8, 0x9e, 0xe8, 0xc2, 0xfd, 0xe6, 0xf1, 0x24, 0x64, 0x37, 0x55, 
 69 |     0x1d, 0xb3, 0xc2, 0x9e, 0xe5, 0xe9, 0x3a, 0x67, 0x45, 0xe1, 0x59, 0xab, 
 70 |     0xe5, 0x9d, 0x12, 0x94, 0x31, 0xf5, 0x0c, 0x27, 0x27, 0x9b, 0x3c, 0x3c, 
 71 |     0x0f, 0xa0, 0xdb, 0xd7, 0x84, 0x69, 0x4b, 0x73, 0x0f, 0xa6, 0x0d, 0x6b, 
 72 |     0x12, 0xc4, 0x28, 0xc8, 0x7d, 0xc3, 0xb7, 0x96, 0xc4, 0xdc, 0x9f, 0xf0, 
 73 |     0xc0, 0x5b, 0x23, 0x31, 0xc8, 0xea, 0xd6, 0x21, 0x4c, 0xd0, 0x09, 0xee, 
 74 |     0x87, 0x61, 0x48, 0xfa, 0x7e, 0xf0, 0x7b, 0x43, 0xd4, 0xf5, 0xf3, 0x9c, 
 75 |     0x81, 0x5b, 0xf2, 0x2b, 0x66, 0xad, 0xab, 0x7b, 0x0c, 0x05, 0xbb, 0x11, 
 76 |     0xbd, 0x1c, 0xb6, 0xe7, 0x43, 0x57, 0x05, 0x54, 0x39, 0xc1, 0x06, 0xb2, 
 77 |     0xc4, 0x37, 0x87, 0xa7, 0x9f, 0x5d, 0x3d, 0x88, 0xcd, 0x9a, 0x49, 0xec, 
 78 |     0x64, 0x56, 0x0f, 0x8a, 0xf0, 0x11, 0x07, 0xae, 0x66, 0x52, 0x0b, 0xf9, 
 79 |     0x15, 0x09, 0x62, 0x5a, 0x14, 0xcb, 0x49, 0x35, 0xc9, 0x4c, 0x94, 0xb1, 
 80 |     0xed, 0x64, 0x73, 0x7c, 0x7a, 0x5e, 0x64, 0xa4, 0x3b, 0xe9, 0xc1, 0x43, 
 81 |     0x85, 0x44, 0x61, 0xd0, 0x74, 0x8e, 0x2a, 0x0b, 0x49, 0x53, 0xe7, 0x6f, 
 82 |     0x1e, 0x2e, 0x27, 0x75, 0x62, 0xa9, 0x9e, 0x4c, 0x4e, 0x7f, 0x96, 0x5f, 
 83 |     0xe5, 0x01, 0xc5, 0xc9, 0xac, 0x7a, 0xaa, 0x72, 0x9f, 0x01, 0xfb, 0x46, 
 84 |     0x54, 0xf5, 0xb3, 0x72, 0xea, 0x3e, 0x54, 0x3a, 0x92, 0xf3, 0x24, 0x2b, 
 85 |     0x05, 0x11, 0xb7, 0x19, 0xcc, 0xbb, 0xd8, 0x86, 0x4c, 0xe4, 0xe9, 0xb2, 
 86 |     0x21, 0xa9, 0x44, 0x98, 0x90, 0x6d, 0x19, 0x0b, 0x9e, 0x81, 0x66, 0x12, 
 87 |     0xa3, 0xe5, 0xa4, 0x9b, 0xd7, 0x3a, 0xdc, 0x14, 0x05, 0x94, 0x36, 0x69, 
 88 |     0x62, 0xdb, 0xf9, 0x02, 0x68, 0x4c, 0xda, 0xa0, 0xd4, 0x7b, 0x31, 0xea, 
 89 |     0xbe, 0x68, 0xd2, 0xe8, 0xd1, 0x79, 0x78, 0x3a, 0xa8, 0xb9, 0x02, 0xa4, 
 90 |     0xcc, 0xd0, 0x7b, 0x1e, 0x9d, 0x87, 0x16, 0x2b, 0xf5, 0x73, 0x4c, 0xcf, 
 91 |     0x5e, 0x46, 0x6a, 0x99, 0x01, 0x74, 0xd2, 0x6a, 0xda, 0xcf, 0x68, 0x85, 
 92 |     0x4d, 0xc7, 0xd5, 0x27, 0xa7, 0xf3, 0x87, 0xe0, 0x7f, 0xb0, 0xa6, 0xb3, 
 93 |     0x57, 0xd4, 0xb1, 0x19, 0xb9, 0xb9, 0x47, 0x08, 0x72, 0x9e, 0x89, 0x53, 
 94 |     0x35, 0x9e, 0x40, 0xea, 0x42, 0x10, 0x04, 0xab, 0x76, 0x48, 0xb2, 0x24, 
 95 |     0x61, 0x1a, 0x94, 0xe0, 0x7c, 0xc2, 0x5f, 0x33, 0x71, 0x1e, 0x33, 0xfc, 
 96 |     0xf8, 0xe2, 0xf6, 0x75, 0xe8, 0x3a, 0x2a, 0xa6, 0x8e, 0x9a, 0x27, 0x5a, 
 97 |     0x2e, 0x95, 0x07, 0xbe, 0x96, 0xee, 0x32, 0xc6, 0xa9, 0x82, 0xd7, 0xc0, 
 98 |     0x08, 0x9d, 0xe2, 0x45, 0xe5, 0x23, 0x03, 0x3c, 0x14, 0xd7, 0x31, 0xf0, 
 99 |     0xa8, 0x98, 0x8f, 0x73, 0xe9, 0x44, 0x90, 0x95, 0xcf, 0x5b, 0x59, 0xb9, 
100 |     0xc7, 0xd9, 0x48, 0x57, 0x31, 0x70, 0x69, 0x4c, 0x79, 0x56, 0x25, 0x7e, 
101 |     0x85, 0xd1, 0xaf, 0x25, 0xcb, 0x6f, 0x7f, 0x62, 0x31, 0x34, 0xe7, 0x69, 
102 |     0xee, 0x3a, 0x7a, 0x8d, 0x18, 0xe0, 0x75, 0x81, 0x09, 0x70, 0x40, 0xa4, 
103 |     0x8e, 0xfb, 0x48, 0x3e, 0x2d, 0xa7, 0x98, 0x09, 0xec, 0xa7, 0x72, 0x20, 
104 |     0x7e, 0x47, 0xc5, 0x06, 0xd8, 0xbc, 0x77, 0x66, 0xce, 0x87, 0x0e, 0x4d, 
105 |     0x54, 0x26, 0xb2, 0x19, 0x22, 0x11, 0x13, 0xc1, 0xe6, 0x55, 0x1a, 0x43, 
106 |     0x3a, 0x3b, 0xab, 0x12, 0x7d, 0xe1, 0x66, 0xb0, 0x6b, 0xda, 0xbb, 0x66, 
107 |     0x42, 0x42, 0xf7, 0x72, 0x06, 0x92, 0x78, 0x91, 0xa4, 0x6f, 0x2a, 0x43, 
108 |     0xf1, 0x1d, 0x6e, 0x58, 0x3e, 0xf8, 0x84, 0xbf, 0xfc, 0x5f, 0xa0, 0x83, 
109 |     0x73, 0xe1, 0xbc, 0xe9, 0xee, 0x72, 0xda, 0x0f, 0x00, 0x5f, 0x6c, 0x58, 
110 |     0xe2, 0x82, 0xe4, 0x19, 0xa8, 0x0b, 0x58, 0x9d, 0x92, 0xe6, 0xb3, 0x8f, 
111 |     0x9a, 0xb8, 0x53, 0xeb, 0x9e, 0x90, 0x0a, 0x8a, 0xf4, 0x9f, 0xfa, 0x04, 
112 |     0x2d, 0x7c, 0xb2, 0x0e, 0x81, 0xc2, 0x19, 0xde, 0xeb, 0xbd, 0x84, 0x1d, 
113 |     0x72, 0x9b, 0x5e, 0xf5, 0xb4, 0xea, 0xf7, 0x1a, 0x37, 0xb9, 0x72, 0xab, 
114 |     0x89, 0x72, 0x67, 0x12, 0x29, 0xa0, 0x88, 0x06, 0xcb, 0xf3, 0x34, 0x47, 
115 |     0xa1, 0xf0, 0xf4, 0x34, 0x66, 0xbe, 0x7c, 0xe0, 0x3a, 0xe7, 0xf2, 0xb9, 
116 |     0x44, 0x0c, 0x6f, 0xf0, 0x2a, 0xb8, 0x9a, 0x1b, 0xc4, 0x62, 0xe1, 0x1c, 
117 |     0x11, 0x49, 0x38, 0xb5, 0x8e, 0x13, 0x7b, 0xf3, 0x68, 0x8a, 0xe8, 0xda, 
118 |     0x77, 0xb5, 0x46, 0x12, 0x1f, 0x54, 0xe2, 0xc2, 0x75, 0x16, 0xce, 0xd4, 
119 |     0xdf, 0xd2, 0x4c, 0xaa, 0x65, 0x81, 0xad, 0xda, 0xfc, 0x1e, 0x13, 0xff, 
120 |     0x91, 0xbc, 0xee, 0xfc, 0x00, 0x3c, 0x90, 0xbe, 0xe1, 0x71, 0xe4, 0x98, 
121 |     0xf0, 0xc8, 0x99, 0x28, 0x73, 0x98, 0x30, 0x64, 0xc5, 0x58, 0xc8, 0x7f, 
122 |     0xc9, 0x72, 0x49, 0x9c, 0x63, 0x87, 0x7c, 0x47, 0x9c, 0x4a, 0x57, 0x87, 
123 |     0x2c, 0x88, 0xcc, 0x03, 0x4e, 0xc5, 0x99, 0xec, 0x34, 0x46, 0x3b, 0x9d, 
124 |     0x73, 0xcd, 0x55, 0xaa, 0x32, 0x8a, 0x4a, 0x90, 0x33, 0xe8, 0x6f, 0xd1, 
125 |     0x6e, 0x75, 0x50, 0x48, 0x35, 0x07, 0xd0, 0xa9, 0xc9, 0xd4, 0x88, 0xaa, 
126 |     0x78, 0x34, 0xfb, 0x1d, 0xc8, 0xa5, 0x3d, 0x6d, 0x95, 0x9d, 0xbe, 0xcc, 
127 |     0xf1, 0x6f, 0x78, 0x21, 0x7c, 0x68, 0x89, 0x5d, 0x07, 0x97, 0xb4, 0xb0, 
128 |     0x53, 0x4e, 0x84, 0x5f, 0xe3, 0x27, 0x62, 0xba, 0xef, 0x1f, 0xd9, 0x6e, 
129 |     0xed, 0x1d, 0x19, 0xa4, 0x77, 0xa1, 0x97, 0x86, 0x44, 0xe3, 0x0c, 0x6d, 
130 |     0xc1, 0x98, 0xab, 0xc3, 0xbe, 0xb1, 0x7d, 0x6d, 0xcf, 0x65, 0x6b, 0x4a, 
131 |     0xb0, 0xea, 0x7f, 0xfe, 0xfd, 0xaf, 0x7f, 0x48, 0x9b, 0xc2, 0x87, 0x7f, 
132 |     0x3a, 0x16, 0xb5, 0xd1, 0xd0, 0x9f, 0xa9, 0xb6, 0xb2, 0x55, 0x57, 0x1b, 
133 |     0x97, 0x06, 0xe9, 0x0d, 0x3a, 0xe0, 0x72, 0x4f, 0x48, 0xd5, 0x9a, 0x34, 
134 |     0xcb, 0x58, 0x12, 0x9e, 0x6d, 0x78, 0x0c, 0x40, 0xb5, 0x78, 0x0c, 0x39, 
135 |     0x80, 0xba, 0x45, 0x39, 0xbe, 0xef, 0x03, 0x3c, 0x22, 0xae, 0x8e, 0x24, 
136 |     0x46, 0xc2, 0xd4, 0x1e, 0x83, 0xf5, 0x60, 0xfa, 0x99, 0xe0, 0xc9, 0x36, 
137 |     0xbc, 0xc3, 0x41, 0xc7, 0xb0, 0x5e, 0x35, 0x38, 0x6c, 0x2b, 0x03, 0x4c, 
138 |     0x69, 0x89, 0xb9, 0xaa, 0x6a, 0x32, 0x18, 0xaa, 0xe9, 0x3e, 0xa1, 0x76, 
139 |     0x78, 0x68, 0x96, 0x71, 0x5e, 0xd6, 0xab, 0xce, 0xf8, 0x4e, 0x90, 0xfa, 
140 |     0xfc, 0x0a, 0xb6, 0xa1, 0x0a, 0x0c, 0xda, 0x2e, 0xd7, 0x09, 0x62, 0x1e, 
141 |     0x7c, 0x84, 0x6c, 0xe2, 0x4e, 0x31, 0x9b, 0x35, 0xe4, 0xd8, 0x0c, 0xbb, 
142 |     0x7b, 0x93, 0x4f, 0x0f, 0x40, 0x46, 0x35, 0x63, 0xf7, 0x50, 0x33, 0x38, 
143 |     0x56, 0xb8, 0xa0, 0xaa, 0x0b, 0xf6, 0x45, 0x60, 0x29, 0x1c, 0x7a, 0x50, 
144 |     0xc9, 0x35, 0x67, 0x6c, 0xd7, 0x28, 0x4c, 0x92, 0xf8, 0x0b, 0x41, 0x52, 
145 |     0x0e, 0x34, 0x6d, 0x35, 0x81, 0x66, 0x8b, 0x9b, 0xee, 0x31, 0x3a, 0xb7, 
146 |     0x1d, 0x61, 0x31, 0xf4, 0x04, 0xa6, 0xf8, 0xa9, 0x32, 0x91, 0x31, 0x82, 
147 |     0xd4, 0x54, 0x20, 0x67, 0x0c, 0xbf, 0xba, 0x4b, 0x42, 0x18, 0xeb, 0xdb, 
148 |     0x24, 0x13, 0x8e, 0xea, 0xb6, 0x31, 0x18, 0x53, 0xd0, 0xa0, 0x6a, 0x91, 
149 |     0x06, 0x60, 0xdc, 0xe9, 0x40, 0x28, 0x15, 0xad, 0x3e, 0x68, 0xb4, 0xae, 
150 |     0x29, 0x07, 0x55, 0x2a, 0xff, 0x05, 0x4f, 0xea, 0x95, 0xb5, 0xb6, 0xb7, 
151 |     0xf3, 0xb3, 0xb2, 0xd8, 0xa8, 0xb4, 0xcf, 0x0d, 0x4d, 0x9b, 0xd6, 0xdd, 
152 |     0x29, 0xdb, 0xc7, 0xfb, 0x8f, 0x75, 0x8a, 0x03, 0x9a, 0x3b, 0x2c, 0x43, 
153 |     0x9a, 0xb9, 0x5f, 0xfd, 0x60, 0x43, 0x6f, 0xd6, 0xeb, 0x48, 0xdb, 0xc1, 
154 |     0xc6, 0xe7, 0x09, 0xd8, 0xed, 0x87, 0x8b, 0xb7, 0x6f, 0xd0, 0xec, 0x8e, 
155 |     0x21, 0x8d, 0x17, 0x3e, 0xf8, 0x84, 0x70, 0x5d, 0x7a, 0x44, 0x56, 0x53, 
156 |     0x4b, 0x43, 0x84, 0x9e, 0x47, 0x5b, 0xb7, 0x5b, 0x55, 0xe5, 0xd3, 0xd6, 
157 |     0x71, 0xd6, 0xf6, 0xa5, 0xd2, 0x1d, 0xfc, 0x38, 0xc5, 0x57, 0xbf, 0x67, 
158 |     0xe9, 0x16, 0x3a, 0x36, 0xe6, 0xae, 0x2a, 0x1f, 0x31, 0x75, 0x93, 0xd6, 
159 |     0x86, 0x8a, 0x1a, 0x4b, 0xaf, 0x77, 0x0c, 0x65, 0xf7, 0xd8, 0xd4, 0x3d, 
160 |     0x99, 0x74, 0x8c, 0xd2, 0xfc, 0x9c, 0x42, 0x63, 0x3a, 0xda, 0xf5, 0x75, 
161 |     0x9b, 0x22, 0x4b, 0x3f, 0x65, 0x10, 0x5f, 0xc5, 0xbc, 0x53, 0x44, 0xdb, 
162 |     0xbd, 0xd3, 0x03, 0x84, 0x05, 0xa0, 0x55, 0x0f, 0x8a, 0x59, 0xb2, 0x86, 
163 |     0x41, 0xe5, 0x94, 0x1c, 0x1b, 0xd1, 0x6e, 0x47, 0xc6, 0x3a, 0xc2, 0x6b, 
164 |     0xe7, 0x40, 0x5b, 0xaf, 0x00, 0xf8, 0x8f, 0x8e, 0x39, 0x93, 0xdc, 0x91, 
165 |     0x15, 0xde, 0x48, 0x38, 0xfd, 0xa8, 0x1e, 0xf1, 0x53, 0xb5, 0x12, 0x21, 
166 |     0x3a, 0xe6, 0x90, 0xdd, 0xcf, 0xd0, 0xf5, 0x44, 0xa6, 0x6a, 0x0f, 0x8b, 
167 |     0x30, 0x4e, 0xb4, 0x9b, 0xdb, 0x11, 0xea, 0xb9, 0x7e, 0x87, 0x98, 0xc0, 
168 |     0x71, 0xd2, 0xd5, 0xf0, 0x6c, 0x7f, 0x93, 0xb3, 0x08, 0x78, 0x5d, 0xce, 
169 |     0x1a, 0x21, 0x9a, 0x41, 0xac, 0x39, 0x68, 0x77, 0x39, 0x1e, 0x67, 0x6d, 
170 |     0x89, 0xf8, 0x9d, 0xa5, 0x6f, 0x06, 0xc8, 0xea, 0xc4, 0xbe, 0xa8, 0x47, 
171 |     0x30, 0x52, 0x6c, 0x99, 0xd8, 0xa4, 0x21, 0xf4, 0x99, 0x7f, 0x3e, 0xbf, 
172 |     0x70, 0xcc, 0x93, 0x97, 0x1c, 0x06, 0xdd, 0xe9, 0xc0, 0x28, 0x08, 0x71, 
173 |     0x08, 0x91, 0xee, 0xc8, 0x9b, 0xb8, 0xea, 0xb0, 0x90, 0x14, 0x65, 0x10, 
174 |     0xc0, 0xb8, 0x1c, 0x95, 0x71, 0x7c, 0x7b, 0xcf, 0xb1, 0x0d, 0x84, 0x77, 
175 |     0xc8, 0x5a, 0x5f, 0x3c, 0x1d, 0x4a, 0xc9, 0xe4, 0x74, 0x08, 0x72, 0x1e, 
176 |     0x30, 0x12, 0xaa, 0x77, 0x1e, 0xa3, 0x15, 0xcb, 0x90, 0x29, 0x95, 0xcb, 
177 |     0x1b, 0x5f, 0x12, 0x77, 0x72, 0xb6, 0x16, 0xa4, 0xfa, 0x06, 0xc3, 0x79, 
178 |     0x1b, 0x9a, 0xac, 0x99, 0xed, 0xc0, 0xd6, 0x63, 0x70, 0x2e, 0xd5, 0xb9, 
179 |     0xc9, 0xe7, 0xcf, 0xfb, 0x29, 0x41, 0x3e, 0x6f, 0x93, 0xc1, 0xdc, 0x98, 
180 |     0x0c, 0x2a, 0x1c, 0xe4, 0x2d, 0x68, 0xb5, 0x61, 0x3a, 0x10, 0xb2, 0x53, 
181 |     0xf3, 0xa5, 0x47, 0x9f, 0x87, 0x45, 0x81, 0x34, 0xdf, 0xbe, 0x94, 0xf7, 
182 |     0x0e, 0x24, 0x61, 0xd7, 0xe4, 0x55, 0xfd, 0xb5, 0x57, 0xed, 0xbe, 0xcf, 
183 |     0x73, 0x7a, 0xeb, 0x47, 0x79, 0xba, 0xad, 0xd9, 0xed, 0x13, 0x31, 0x7e, 
184 |     0xb5, 0xb8, 0x6a, 0xc3, 0xbc, 0xce, 0xa3, 0xd5, 0xbd, 0x59, 0xf1, 0xfe, 
185 |     0x03, 0x60, 0x8a, 0x9f, 0x0e, 0x48, 0xa3, 0x95, 0x90, 0x37, 0x9b, 0xbc, 
186 |     0x96, 0xef, 0x6f, 0x6f, 0xdf, 0xfc, 0x20, 0x44, 0xf6, 0x57, 0xf6, 0x6b, 
187 |     0xc9, 0x0a, 0xd1, 0x93, 0x12, 0x08, 0x7d, 0xec, 0x30, 0x5c, 0xe7, 0xdd, 
188 |     0x8f, 0x3f, 0x5d, 0xc0, 0x31, 0xce, 0xcc, 0x70, 0x4b, 0xd7, 0x50, 0x56, 
189 |     0x4b, 0x06, 0xcb, 0x37, 0x57, 0x4f, 0x68, 0x7b, 0x86, 0x4b, 0x43, 0xe5, 
190 |     0x54, 0x12, 0xd4, 0x26, 0xc5, 0xe2, 0x58, 0x0a, 0xba, 0x8a, 0xed, 0x35, 
191 |     0xb5, 0xbe, 0x04, 0x63, 0x39, 0xbe, 0x49, 0x40, 0x7a, 0x8c, 0x5e, 0xd0, 
192 |     0xae, 0xe1, 0x03, 0x12, 0x41, 0x30, 0xcf, 0x48, 0xf5, 0x55, 0xa4, 0x82, 
193 |     0xc6, 0x53, 0xf2, 0x08, 0xdf, 0x9c, 0x58, 0x22, 0xba, 0x7b, 0x37, 0x57, 
194 |     0xe7, 0xfc, 0xf6, 0x9d, 0x09, 0x66, 0x4f, 0xcb, 0x5b, 0x93, 0x07, 0x9f, 
195 |     0x34, 0x31, 0x76, 0xcd, 0x6b, 0x14, 0xc3, 0xca, 0xf4, 0x72, 0xe4, 0x7c, 
196 |     0xbc, 0xcf, 0xd3, 0x9a, 0xfc, 0xcb, 0x07, 0x9f, 0xde, 0x62, 0x02, 0x8d, 
197 |     0xe2, 0x14, 0xb2, 0x82, 0xc6, 0x72, 0xba, 0x7b, 0x68, 0x63, 0x89, 0xb0, 
198 |     0xf6, 0x10, 0x82, 0xa6, 0x01, 0x40, 0xb0, 0xe2, 0x8a, 0x3f, 0x05, 0x13, 
199 |     0x17, 0x7c, 0xcb, 0xd2, 0x52, 0x0c, 0xa7, 0xcf, 0x6e, 0xa0, 0xc9, 0xcb, 
200 |     0xd1, 0xc3, 0x6a, 0xe5, 0x57, 0xc8, 0xa6, 0x7b, 0x67, 0x3f, 0x22, 0xcf, 
201 |     0x40, 0x1d, 0x0b, 0xc5, 0x6e, 0xb4, 0xad, 0x32, 0x04, 0x8b, 0xf4, 0x7e, 
202 |     0x59, 0x25, 0xd1, 0x9f, 0x86, 0x7c, 0x16, 0x29, 0x0b, 0x41, 0x45, 0x59, 
203 |     0x48, 0x5c, 0x1f, 0x0f, 0xe0, 0xaa, 0x96, 0x9a, 0x0a, 0xaf, 0x83, 0x6b, 
204 |     0xcd, 0x80, 0x67, 0x38, 0xf5, 0xab, 0x9e, 0xa0, 0x36, 0xef, 0x3d, 0x1b, 
205 |     0xd2, 0x77, 0x31, 0xe9, 0x17, 0x99, 0xf3, 0x33, 0x4d, 0x69, 0x37, 0xa3, 
206 |     0xbd, 0x43, 0x6b, 0xd2, 0x80, 0x52, 0x30, 0x6b, 0x38, 0x22, 0x0a, 0x30, 
207 |     0x87, 0x58, 0x2a, 0xd1, 0x42, 0xcd, 0xbd, 0x31, 0xe2, 0x77, 0x40, 0xa3, 
208 |     0xbd, 0xb3, 0x38, 0x44, 0x5d, 0xa4, 0xed, 0x1e, 0x31, 0x24, 0x8b, 0xdf, 
209 |     0xb3, 0x6e, 0xff, 0x98, 0x41, 0xdc, 0x8d, 0xdd, 0xab, 0xf4, 0x3f, 0xac, 
210 |     0x08, 0x4d, 0x85, 0x98, 0xf6, 0xdf, 0x56, 0x6a, 0xbd, 0xac, 0xbd, 0x1f, 
211 |     0xa8, 0x06, 0x38, 0x95, 0xc3, 0x81, 0xb6, 0x3c, 0x99, 0xed, 0xdf, 0x28, 
212 |     0x9d, 0xcc, 0xea, 0xd7, 0xa0, 0xf2, 0xdd, 0x28, 0xfe, 0x0f, 0xb6, 0xff, 
213 |     0x05, 0xe6, 0x79, 0xa4, 0x7b, 0x70, 0x2b, 0x00, 0x00
214 | };
215 | 
216 | #endif


---------------------------------------------------------