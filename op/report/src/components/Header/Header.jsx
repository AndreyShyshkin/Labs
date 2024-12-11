import {
  Listbox,
  ListboxButton,
  ListboxOption,
  ListboxOptions,
} from "@headlessui/react";
import { CheckIcon, ChevronUpDownIcon } from "@heroicons/react/20/solid";
import { useEffect, useRef, useState } from "react";
import { Link, useLocation, useNavigate } from "react-router-dom";

const labs = [
  { id: 1, name: "Home", link: "/" },
  { id: 2, name: "Лабораторна работа №1", link: "/lab1" },
  { id: 3, name: "Лабораторна работа №2", link: "/lab2" },
  { id: 4, name: "Лабораторна работа №3", link: "/lab3" },
  { id: 5, name: "Лабораторна работа №4", link: "/lab4" },
  { id: 6, name: "Лабораторна работа №5", link: "/lab5" },
  { id: 7, name: "Лабораторна работа №6", link: "/lab6" },
  { id: 8, name: "Лабораторна работа №7", link: "/lab7" },
  { id: 9, name: "Лабораторна работа №8", link: "/lab8" },
  { id: 10, name: "Лабораторна работа №9", link: "/lab9" },
];

export default function Header() {
  const navigate = useNavigate();
  const location = useLocation();
  const [selected, setSelected] = useState();
  const [listboxWidth, setListboxWidth] = useState(0);
  const listboxRef = useRef(null);

  useEffect(() => {
    const currentPath = location.pathname;
    const currentLab =
      labs.find(
        (lab) =>
          currentPath === lab.link || currentPath.startsWith(`${lab.link}/`),
      ) || labs[0];
    setSelected(currentLab);
  }, [location.pathname]);

  useEffect(() => {
    if (listboxRef.current) {
      const maxWidth = Math.max(
        ...labs.map((lab) => {
          const tempSpan = document.createElement("span");
          tempSpan.style.visibility = "hidden";
          tempSpan.style.position = "absolute";
          tempSpan.style.whiteSpace = "nowrap";
          tempSpan.innerText = lab.name;
          document.body.appendChild(tempSpan);
          const width = tempSpan.offsetWidth;
          document.body.removeChild(tempSpan);
          return width;
        }),
      );
      setListboxWidth(maxWidth + 60);
    }
  }, []);

  return (
    <header className="absolute inset-x-0 top-0 z-50">
      <nav
        aria-label="Global"
        className="flex items-center justify-between py-6 px-6 lg:px-8 max-w-screen-xl mx-auto"
      >
        <div className="flex lg:flex-1">
          <Link to="/" className="-m-1.5 p-1.5">
            <span className="sr-only">HomeLabs</span>
            <img
              alt=""
              src="https://cdn-icons-png.flaticon.com/256/3721/3721643.png"
              className="h-8 w-auto"
            />
          </Link>
        </div>
        <p className="hidden lg:flex m-auto text-lg text-center leading-2 text-gray-600">
          Київський ніціональний універститет імені Тараса Шевченка
          <br />
          Факультет інформаційних технологій
        </p>
        <div className="flex flex-1 justify-end">
          <Listbox value={selected} onChange={setSelected}>
            <div
              className="relative mt-2"
              ref={listboxRef}
              style={{ width: `${listboxWidth}px` }}
            >
              <ListboxButton className="relative w-full cursor-pointer rounded-md bg-white py-1.5 pl-3 pr-10 text-left text-gray-900 shadow-sm ring-1 ring-inset ring-gray-300 focus:outline-none focus:ring-2 focus:ring-indigo-500 sm:text-sm sm:leading-6">
                <span className="flex items-center">
                  {selected ? (
                    <span className="ml-3 block truncate">{selected.name}</span>
                  ) : (
                    <span className="ml-3 block truncate">Loading...</span>
                  )}
                </span>
                <span className="pointer-events-none absolute inset-y-0 right-0 ml-3 flex items-center pr-2">
                  <ChevronUpDownIcon
                    aria-hidden="true"
                    className="h-5 w-5 text-gray-400"
                  />
                </span>
              </ListboxButton>
              <ListboxOptions className="absolute z-10 mt-1 max-h-56 w-full overflow-auto rounded-md bg-white py-1 text-base shadow-lg ring-1 ring-black ring-opacity-5 focus:outline-none sm:text-sm">
                {labs.map((lab) => (
                  <ListboxOption
                    key={lab.id}
                    value={lab}
                    className={({ active }) =>
                      `relative cursor-pointer select-none py-2 pl-3 pr-9 ${
                        active ? "bg-indigo-600 text-white" : "text-gray-900"
                      }`
                    }
                    onClick={() => navigate(lab.link)}
                  >
                    {({ selected, active }) => (
                      <>
                        <span
                          className={`block truncate ${
                            selected ? "font-semibold" : "font-normal"
                          }`}
                        >
                          {lab.name}
                        </span>
                        {selected ? (
                          <span
                            className={`absolute inset-y-0 right-0 flex items-center pr-4 ${
                              active ? "text-white" : "text-indigo-600"
                            }`}
                          >
                            <CheckIcon className="h-5 w-5" aria-hidden="true" />
                          </span>
                        ) : null}
                      </>
                    )}
                  </ListboxOption>
                ))}
              </ListboxOptions>
            </div>
          </Listbox>
        </div>
      </nav>
    </header>
  );
}
