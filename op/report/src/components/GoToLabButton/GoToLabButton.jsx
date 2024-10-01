import { useLocation, useNavigate } from 'react-router-dom'

export default function GoToLabButton() {
	const location = useLocation()
	const navigate = useNavigate()

	const handleGoToLab = () => {
		const pathParts = location.pathname.split('/')

		if (pathParts.length > 1) {
			const basePath = pathParts[1]

			navigate(`/${basePath}`)
		}
	}

	return (
		<button className='text-gray-400 py-2' onClick={handleGoToLab}>
			&lt; Повернутися до каталогу
		</button>
	)
}
