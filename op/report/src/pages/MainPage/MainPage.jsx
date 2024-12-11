import { Link } from "react-router-dom";
import BackGroundDown from "../../components/BackGround/BackGroundDown";
import BackGroundUp from "../../components/BackGround/BackGroundUp";
import "./MainPage.css";

export default function MainPage() {
  return (
    <div className="bg-white">
      <div className="relative isolate px-6 pt-14 lg:px-8">
        <BackGroundUp />
        <div className="max-w-screen-xl m-auto px-6 lg:px-8 py-32 sm:py-48 lg:py-56 block lg:flex justify-between">
          <div className="text-left">
            <h1 className="text-4xl max-w-3xl	 font-bold tracking-tight text-gray-900 sm:text-6xl">
              Звіти по лабораторних роботах по ОП
            </h1>
            <p className="mt-6 text-lg leading-8 text-gray-600">
              Виконав Шишкін Андрій ІПЗ-11.1
              <br />
              Викладач Ковалюк Тетяна Володимирівна
            </p>
          </div>
          <div className="labs block">
            <div className="block sm:flex">
              {" "}
              <Link
                className="mt-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                to="/lab1"
              >
                Лабораторна работа №1
              </Link>
              <Link
                className="mt-6 sm:mx-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                to="/lab2"
              >
                Лабораторна работа №2
              </Link>
              <Link
                className="mt-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                to="/lab3"
              >
                Лабораторна работа №3
              </Link>
            </div>
            <div className="block sm:flex">
              {" "}
              <Link
                className="mt-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                to="/lab4"
              >
                Лабораторна работа №4
              </Link>
              <Link
                className="mt-6 sm:mx-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                to="/lab5"
              >
                Лабораторна работа №5
              </Link>
              <Link
                className="mt-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                to="/lab6"
              >
                Лабораторна работа №6
              </Link>
            </div>
            <div className="block sm:flex">
              {" "}
              <Link
                className="mt-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                to="/lab7"
              >
                Лабораторна работа №7
              </Link>
              <Link
                className="mt-6 sm:mx-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                to="/lab8"
              >
                Лабораторна работа №8
              </Link>
              <Link
                className="mt-6 flex w-full items-center justify-center rounded-md border border-transparent bg-indigo-600 px-8 py-3 text-base font-medium text-white hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2"
                to="/lab9"
              >
                Лабораторна работа №9
              </Link>
            </div>
          </div>
        </div>
        <BackGroundDown />
      </div>
    </div>
  );
}
