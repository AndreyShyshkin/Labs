import { lazy, StrictMode, Suspense } from 'react'
import { createRoot } from 'react-dom/client'
import { createBrowserRouter, RouterProvider } from 'react-router-dom'
import './index.css'
import Layout from './Layout.jsx'
import LabsKatalog from './pages/LabsKatalog/LabsKatalog.jsx'
import MainPage from './pages/MainPage/MainPage.jsx'

const labsRoutes = [1, 2].map(labNumber => {
	const MetaComponent = lazy(() =>
		import(`./pages/lab${labNumber}/MetaLab.jsx`)
	)
	const UmovaComponent = lazy(() =>
		import(`./pages/lab${labNumber}/UmovaLab.jsx`)
	)
	const AnalizComponent = lazy(() =>
		import(`./pages/lab${labNumber}/AnalizLab.jsx`)
	)
	const BlockComponent = lazy(() =>
		import(`./pages/lab${labNumber}/BlockLab.jsx`)
	)
	const CodeComponent = lazy(() =>
		import(`./pages/lab${labNumber}/CodeLab.jsx`)
	)
	const VikonanieComponent = lazy(() =>
		import(`./pages/lab${labNumber}/VikonanieLab.jsx`)
	)
	const PereverkaComponent = lazy(() =>
		import(`./pages/lab${labNumber}/PereverkaLab.jsx`)
	)
	const VysnovokComponent = lazy(() =>
		import(`./pages/lab${labNumber}/VysnovokLab.jsx`)
	)

	return [
		{
			path: `/lab${labNumber}`,
			element: <LabsKatalog />,
		},
		{
			path: `/lab${labNumber}/meta-roboti`,
			element: <MetaComponent />,
		},
		{
			path: `/lab${labNumber}/umova-roboti`,
			element: <UmovaComponent />,
		},
		{
			path: `/lab${labNumber}/analiz-roboti`,
			element: <AnalizComponent />,
		},
		{
			path: `/lab${labNumber}/block-scheme`,
			element: <BlockComponent />,
		},
		{
			path: `/lab${labNumber}/code-programm`,
			element: <CodeComponent />,
		},
		{
			path: `/lab${labNumber}/vikonanie-programm`,
			element: <VikonanieComponent />,
		},
		{
			path: `/lab${labNumber}/perverka-dostovirnosti`,
			element: <PereverkaComponent />,
		},
		{
			path: `/lab${labNumber}/vysnovok`,
			element: <VysnovokComponent />,
		},
	]
})

const router = createBrowserRouter([
	{
		path: '/',
		element: <Layout />,
		children: [
			{
				index: true,
				element: <MainPage />,
			},
			...labsRoutes.flat(),
		],
	},
])

createRoot(document.getElementById('root')).render(
	<StrictMode>
		<Suspense fallback={<div>Loading...</div>}>
			<RouterProvider router={router} />
		</Suspense>
	</StrictMode>
)
